#include "lib.h"

#include <stdio.h>

int fattoriale(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fattoriale(n-1);
}

void stampa(int i) {
    printf("Il fattoriale di %d è uguale a %d\n", i, fattoriale(i));
}
