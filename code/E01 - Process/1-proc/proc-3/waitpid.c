#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t child_procs[10];
    int exit_status;

    for (int i = 0; i < 10; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            // child
            printf("Child con PID=%d in esecuzione\n", (int)getpid());
            exit(i);
        } else {
            // parent
            child_procs[i] = pid;
        }
    }

    printf("Parent: attendo il termine dell'esecuzione del child numero 4\n");
    waitpid(child_procs[4], &exit_status, 0);
    printf("Parent: processo %d terminato con status %d\n",
            child_procs[4], WEXITSTATUS(exit_status));

    printf("Parent: attendo il termine dell'esecuzione degli altri\n");
    for (int i = 0; i < 9; i++) {
        pid_t pid = wait(&exit_status);
        printf("Parent: processo %d terminato con status %d\n",
                pid, WEXITSTATUS(exit_status));
    }
    return 0;
}
