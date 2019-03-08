int twice = 0;

// variabile accessibile soltanto da questo file
static int global = 0;

// funzione accessibile soltanto da questo file
static void inc(void)
{
    global++;
    twice = global * 2;
}

void f(void)
{
    inc();
}

int g(void)
{
    return global;
}
