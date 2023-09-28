#include <malloc.h>
#include <pthread.h>
#include <sched.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define FIBER_STACK 1024*64

struct c {
    int saldo;
};
typedef struct c conta;

conta from, to;
int valor;
pthread_mutex_t mtx;
static int flag = 0;

void* transferencia(void* arg) {
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
    pthread_t threads[10];
    pthread_mutex_init(&mtx, NULL);

    from.saldo = 100;
    to.saldo = 100;
    printf("Transferindo 10 para a conta c2\n");
    valor = 10;

    for (int i = 0; i < 10; i++) {
        if (pthread_create(&threads[i], NULL, transferencia, NULL)) {
            perror("pthread_create");
            exit(2);
        }
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mtx);
    printf("Transferências concluídas e memória liberada.\n");
    return 0;
}
