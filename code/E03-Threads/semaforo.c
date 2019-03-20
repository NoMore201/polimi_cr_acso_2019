#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAXN 5

char carattere = '\0';
sem_t semaforo;

void* consumer(void *arg) {
    sem_wait(&semaforo);
    printf("Letto %c\n", carattere);
    return NULL;
}

void* producer(void *arg) {
    printf("Generato carattere\n");
    carattere = (rand()%93)+33;
    sem_post(&semaforo);
    return NULL;
}

int main() {
    pthread_t th1, th2;

    srand( time( NULL ) );
    sem_init(&semaforo , 0, 0);

    for(int i = 0; i < MAXN; i++) {
        pthread_create(&th1, NULL , producer , NULL);
        pthread_create(&th2, NULL , consumer , NULL);
        pthread_join(th1, NULL);
        pthread_join(th2, NULL);
    }

    return 0;
}
