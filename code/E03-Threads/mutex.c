#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NTHREAD  2
#define MAXSLEEP 3

int a = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* increment(void* arg) {
    int j = NTHREAD;
    while (j > 0) {
        pthread_mutex_lock(&mutex);
        a++;
        printf("Increment: Tread n. %d, valore attuale di a=%d\n", (int)arg, a);
        pthread_mutex_unlock(&mutex);
        sleep(rand()%MAXSLEEP);
        j--;
    }

    pthread_exit(arg);
}

void* decrement(void* arg) {
    int j = NTHREAD;
    while (j > 0) {
        pthread_mutex_lock(&mutex);
        a--;
        printf("Decrement: Tread n. %d, valore attuale di a=%d\n", (int)arg, a);
        pthread_mutex_unlock(&mutex);
        sleep(rand()%MAXSLEEP);
        j--;
    }

    pthread_exit(arg);
}

int main(int argc, char *argv[])
{
    pthread_t inc[NTHREAD], dec[NTHREAD];    
    int i;
    void* ret;

    srand(time(NULL));
    printf("Processo padre, creo threads\n");

    for (i = 0; i < NTHREAD; i++) {
        pthread_create( &inc[i], NULL, increment, (void*)i );
    }

    for (i = 0; i < NTHREAD; i++) {
        pthread_create( &dec[i], NULL, decrement, (void*)i );
    }

    for (i = 0; i < NTHREAD; i++) {
        pthread_join(inc[i], &ret);
        printf("Thread incremento n. %d ha terminato l'esecuzione\n",
                (int)ret);
    }

    for (i = 0; i < NTHREAD; i++) {
        pthread_join(dec[i], &ret);
        printf("Thread decremento n. %d ha terminato l'esecuzione\n",
                (int)ret);
    }

    printf("Processo padre: valore finale di a=%d\n", a);

    return 0;
}
