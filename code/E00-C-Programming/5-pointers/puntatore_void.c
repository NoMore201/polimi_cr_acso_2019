#include <stdio.h>

int j = 6;

void* get() {
	return &j;
}

int main(int argc, char *argv[]) {
	int *pippo = get();
	printf("%d\n", *pippo);
	return 0;
}
