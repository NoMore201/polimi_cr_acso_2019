#include <stdio.h>

typedef union {
    int  valore;
    char byte[4];
} aint;

int main()
{
    aint a;

    a.valore = 32;

    for (int i = 0; i < 4; i++) {
        printf("0x%x\n", a.byte[i] );
    }

    return 0;
}
