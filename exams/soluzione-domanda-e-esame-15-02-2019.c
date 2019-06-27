#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int n_threads, max_number;
int shared = 1;

void* thread_func(void* arg) {
	int n;

	pthread_mutex_lock(&mutex);
	// critical section
	n = shared;
	shared++;
	pthread_mutex_unlock(&mutex);

	for (int i = 1; i <= n; i++) {
		float fValue = (float) n / i;
		if (fValue == i) {
			printf("%d ", n);
			break;
		}
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t* thread_list;

	if (argc != 3) {
		printf("Usage: ./pprimes n_threads max\n");
		return 1;
	}

	// inizializzo le variabili globali con gli argomenti passati
	// da riga di comando
	n_threads = atoi(argv[1]);
	max_number = atoi(argv[2]);

	pthread_t trylist[n_threads];

	// poichè il numero di thread che devo usare dipende dal valore
	// di n_threads, devo allocare dinamicamente il vettore tramite una malloc
	thread_list = malloc( sizeof(pthread_t) * n_threads );
	while (shared <= max_number) {
		// ogni iterazione verranno lanciati un numero di thread pari
		// a n_threads, quindi verrano calcolati n_threads numer alla volta
		// utilizzo una variabile remaining per capire quanti numeri sono rimasti
		// da calcolare
		int remaining = n_threads;
		if (shared + remaining > max_number) {
			remaining = max_number - shared + 1;
		}
		// inizializzo N threads
		for (int i = 0; i < remaining; i++) {
			pthread_create( &thread_list[i], NULL, thread_func, NULL );
		}
		// aspetto gli N threads prima di proseguire
		for (int i = 0; i < remaining; i++) {
			pthread_join( thread_list[i], NULL );
		}
	}

	free(thread_list);
	return 0;
}
