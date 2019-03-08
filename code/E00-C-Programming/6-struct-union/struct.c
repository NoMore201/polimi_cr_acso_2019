#include <stdio.h>

typedef struct {
    int x;
    int y;
} punto;

struct triangolo {
    punto vertici[3];
};

struct quadrato {
    punto vertici[4];
};

void stampa_punto(punto *p) {
    printf("Punto x=%d, y=%d\n", p->x, p->y);
}

void stampa_triangolo(struct triangolo *p) {
    printf("Vertici del triangolo:\n");
    for (int i = 0; i < 3; i++) {
        stampa_punto( &(p->vertici[i]) );
    }
}

int main(void)
{
    punto p1;

    p1.x = 1;
    p1.y = 1;

    punto p2 = {3, 3};
    punto p3 = {.x = 5, .y = 3};

    struct triangolo t = { {p1, p2, p3} };
    stampa_triangolo( &t );

    return 0;
}
