#define N 47

#define INC(x) x++
#define DEC(x) x--

#ifdef DEBUG
#include <stdio.h>
#endif

int main() {
    int x = N;
    int y = INC(x);

#ifdef DEBUG
    printf("x=%d, y=%d\n", x, y);
#endif

    return 0;
}
