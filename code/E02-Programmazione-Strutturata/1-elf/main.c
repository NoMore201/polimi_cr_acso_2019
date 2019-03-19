// initialized global variable
int global1 = 20;

// uninitialized global variable
int global2;

// extern variable
extern int global3;

int inc(int i) {
	return ++i;
}

extern int dec(int i);

int main(void)
{
	inc(global2);
	dec(global3);
	return 0;
}
