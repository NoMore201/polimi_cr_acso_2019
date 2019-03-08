#include <stdio.h>

int main(int argc, char *argv[])
{
	int  a[4] = {1, 10, 100, 1000};
	int  b[4] = {1, 2, 3, 4};
	printf("Valore secondo elemento : %d\n", a[1] );

	int *p = a;
	for (int i = 0; i < 4; i++) {
		printf("%d\n", *p);
		p++;
	}

	return 0;
}
