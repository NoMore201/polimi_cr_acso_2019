#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>

#define NTHREADS 2
#define NITER    2
#define MAXSLEEP 3

int a=0;
sem_t sem;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;


void* producer (void* arg) {
    int j = NITER;
    while (j > 0) {
        pthread_mutex_lock(&mutex);
        a++;
        printf("Producer %d, valore di a: %d\n", (int) arg, a);
        sem_post(&sem);
        pthread_mutex_unlock(&mutex);
        j--;
        sleep(rand()%MAXSLEEP);
    }

    return arg;
}

void* consumer (void* arg) {
    int j = NITER;
    while (j>0) {
        sem_wait(&sem);
        pthread_mutex_lock(&mutex);
        a--;
        printf("Consumer %d, valore di a: %d\n", (int) arg,a);
        pthread_mutex_unlock(&mutex);
        j--;
        sleep(rand()%MAXSLEEP);
    }
    return arg;
}


int main ()
{
    pthread_t prod[NTHREADS], cons[NTHREADS];
    int i,retval;
    sem_init(&sem,0,0);

    srand(time(NULL));
    printf("Sono il processo padre\n");

    for (i = 0; i < NTHREADS; i++) {
         pthread_create(&prod[i], NULL, &producer, (void *)i);
    }

    for (i = 0; i < NTHREADS; i++) {
         pthread_create(&cons[i], NULL, &consumer, (void *)i);
    }

    for (i = 0; i < NTHREADS; i++) {
        pthread_join(prod[i], (void*)&retval);
        printf("Joined producer %d\n", retval);
    }

    for (i = 0; i < NTHREADS; i++) {
        pthread_join(cons[i], (void*)&retval);
        printf("Joined consumer %d\n", retval);
    }

    printf("Sono il processo padre, valore finale di a: %d\n", a);
    sem_destroy(&sem);

    return 0;
}
