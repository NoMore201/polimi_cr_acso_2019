#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    void *handle;
    void (*stampa)(int);
    char *error;

    if (argc != 2) {
        printf("Usage: ./main /path/to/libsample.so\n");
        exit(EXIT_FAILURE);
    }

    handle = dlopen(argv[1], RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Errore nell'aprire la libreria\n");
        exit(EXIT_FAILURE);
    }

    stampa = dlsym(handle, "stampa");
    if ( (error = dlerror()) != NULL) {
        fprintf(stderr, "Errore: %s\n", error);
        exit(EXIT_FAILURE);
    }

    stampa(5);

    return 0;
}
