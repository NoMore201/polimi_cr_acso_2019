#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SIZE 256

const char text_file[] = "./LOG.TXT";
const char msg[] = "Hello World!";

void read_file() {
    FILE *f;
    char buffer[BUF_SIZE] = {0};
    pid_t pid;
    int status_code;

    f = fopen(text_file, "r");
    printf("Contenuto del file %s:\n\n", text_file);

    pid = fork();
    if (pid == 0) {
        // child
        fgets(buffer, BUF_SIZE, f);
        printf("Child reads: %s", buffer);
    } else {
        // parent
        wait(&status_code);
        printf("Processo child terminato con status %d\n", status_code);
        fgets(buffer, BUF_SIZE, f);
        printf("Parent reads: %s", buffer);
    }
}

void write_to_file() {
    FILE  *f;
    pid_t pid;
    int status_code;

    f = fopen(text_file, "w");

    pid = fork();
    if (pid == 0) {
        // child
        printf("Child scrive nel file %s\n", text_file);
        fprintf(f, "Child says: my PID is %d\n", (int)getpid());
    } else {
        // parent
        wait(&status_code);
        printf("Processo child terminato con status %d\n", status_code);
        printf("Parent scrive nel file %s\n", text_file);
        fprintf(f, "Parent says: my PID is %d\n", (int)getpid());
    }
}

int main() {
    write_to_file();
    return 0;
}
