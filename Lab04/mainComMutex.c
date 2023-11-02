// Kaiki Bellini Barbosa - 32249969 
//Linus Leonan Kiche Madera - 32234961 
//Luana Miho Yasuda - 42148677

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 4 // contagem de threads
#define NUM_RUNS 8 // 1uantas vezes repetir o calculo

long long n = 1e6; //numero de termos para calcular pi/4
double sum = 0.0;  //soma para calcular pi
int thread_count = THREAD_COUNT;
pthread_mutex_t mutex_sum;

void* Thread_sum(void* rank);

int main() {
    long thread;
    pthread_t* thread_handles;
    pthread_mutex_init(&mutex_sum, NULL);

    thread_handles = malloc(thread_count * sizeof(pthread_t));

    for (int run = 0; run < NUM_RUNS; run++) {
        sum = 0.0;

        for (thread = 0; thread < thread_count; thread++) {
            pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*) thread);
        }

        for (thread = 0; thread < thread_count; thread++) {
            pthread_join(thread_handles[thread], NULL);
        }

        // a soma representa pi/4, por isso fazemos a multiplicacao por 4.
        printf("Execucao numero %d - Valor calculado para pi: %f\n", run + 1, 4 * sum);
    }

    free(thread_handles);
    pthread_mutex_destroy(&mutex_sum);

    return 0;
}

//Funcao que ja estava disponivel no moodle
void* Thread_sum(void* rank) {
    long my_rank = (long) rank;
    double factor, my_sum = 0.0;
    long long i;
    long long my_n = n/thread_count;
    long long my_first_i = my_n*my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0) // my_first_i is even
        factor = 1.0;
    else  // my_first_i is odd
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        my_sum += factor/(2*i+1);
    }

    pthread_mutex_lock(&mutex_sum);
    sum += my_sum;
    pthread_mutex_unlock(&mutex_sum);

    return NULL;
}
