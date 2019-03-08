#include <stdio.h>

void (*func) (int);

void printer(int i) {
	printf("Printing %d\n", i);
}

void computing( void (*f) (int) ) {
	int n = 123;
	f(n);
}

int main(int argc, char *argv[])
{
	computing(printer);
	return 0;
}
