#include "file.h"

void write_to_file(FILE *f, const char *str) {
    fprintf(f, "%s\n", str);
}

void print_file(FILE *f) {
    rewind(f);
    char buffer[256] = {0};
    while( fgets(buffer, 256, f) ) {
        printf("%s", buffer);
    }
}
