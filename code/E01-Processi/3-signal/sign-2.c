#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


void custom_alarm( int seconds ) {
    // sleep per 10 secondi
    sleep(seconds);
    kill(getpid(), SIGALRM);
}

void alarm_handler( int sig ) {
    if (sig == SIGALRM) {
        printf( "Allarme ricevuto, sono passati 10 secondi\n" );
        exit( 1 );
    }
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &alarm_handler;


    // Registro l'handler
    if ( sigaction(SIGALRM, &sa, NULL) != 0 ) {
        printf( "Errore nel registrare l'handler per SIGALARM\n" );
        exit( 1 );
    } 

    printf( "Ho impostato l'allarme, scatterà tra 10 secondi\n" );
    custom_alarm( 10 ); 

    while(1);

    return 0;
}

