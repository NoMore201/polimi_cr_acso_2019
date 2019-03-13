#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int exit_status;
    char *argv[] = {"./programma", "--output", "file1", NULL};

    pid = fork();
    if (pid == 0) {
        printf("Child: avvio %s\n", argv[0]);
        execvp(argv[0], argv);
        printf("Verrò stampato?\n");
    } else {
        waitpid(pid, &exit_status, 0);
        printf("Processo child ha terminato l'esecuzione con status %d\n", WEXITSTATUS(exit_status));
    }

    return 0;
}
