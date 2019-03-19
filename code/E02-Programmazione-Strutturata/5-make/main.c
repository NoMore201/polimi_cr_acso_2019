#include "file.h"

#include <stdio.h>

int main(void)
{
    FILE *fl = fopen("log.txt", "w+");
    write_to_file(fl, "PRIMA RIGA");
    write_to_file(fl, "SECONDA RIGA");
    print_file(fl);
    fclose(fl);
    return 0;
}
