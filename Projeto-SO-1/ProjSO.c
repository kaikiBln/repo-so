#include <malloc.h>
#include <pthread.h>
#include <sched.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define STACK_SIZE 1024 * 64

static int flag = 0;

typedef struct {
    int saldo;
} Conta;

Conta from, to;
int valor;
pthread_mutex_t mtx;

void* realizarTransferencia(void* param) {
    pthread_mutex_lock(&mtx);

    if (from.saldo >= valor && flag == 0) {
        from.saldo -= valor;
        to.saldo += valor;
        if (from.saldo < 0) {
            to.saldo -= valor;
            from.saldo += valor;
        }
        if (from.saldo == 0) flag = 1;
    }

    if (to.saldo >= valor && flag == 1) {
        to.saldo -= valor;
        from.saldo += valor;
        if (to.saldo < 0) {
            from.saldo -= valor;
            to.saldo += valor;
        }
        if (to.saldo == 0) flag = 0;
    }

    printf("Transferência realizada!\nSaldo de c1: $%d\nSaldo de c2: $%d\n", from.saldo, to.saldo);
    pthread_mutex_unlock(&mtx);
    return NULL;
}

int main() {
    void* stackMemory;
    pthread_t threadArray[100];

    stackMemory = malloc(STACK_SIZE);
    if (!stackMemory) {
        fprintf(stderr, "Erro ao alocar memória para a pilha.\n");
        return EXIT_FAILURE;
    }

    pthread_mutex_init(&mtx, NULL);
    from.saldo = 300;
    to.saldo = 0;

    printf("Iniciando transferência de $1 para a conta c2.\n");
    valor = 50;

    for (int idx = 0; idx < 100; idx++) {
        if (pthread_create(&threadArray[idx], NULL, realizarTransferencia, NULL)) {
            fprintf(stderr, "Erro ao criar thread.\n");
            return EXIT_FAILURE;
        }
    }

    for (int idx = 0; idx < 100; idx++) {
        if (pthread_join(threadArray[idx], NULL)) {
            fprintf(stderr, "Erro ao juntar thread.\n");
            return EXIT_FAILURE;
        }
    }

    pthread_mutex_destroy(&mtx);
    free(stackMemory);

    printf("Todas as transferências foram realizadas e a memória foi liberada.\n");
    return EXIT_SUCCESS;
}
