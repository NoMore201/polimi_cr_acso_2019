#include <stdio.h>

int main() {
    int   i;
    int   a[4] = { 300, 1, 2, 3 };
    char  b[4] = {  30, 2, 0, 0 };
    char *p    = (char*) a;
    int  *p2   = (int*) b;

    for(i = 0; i<4;i++) {
        printf("%d\n", *p);
        p++;
    }

    printf("%d\n", *p2);

    return 0;
}
