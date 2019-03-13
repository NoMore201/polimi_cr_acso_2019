#include <stdio.h>

#define BUF_SIZE 256

const char text_file[] = "./LOG.TXT";
const char msg[] = "Hello World!";

int main()
{
    FILE *f = fopen(text_file, "w");
    
    fprintf(f, "%s\n", msg);
    return 0;
}
