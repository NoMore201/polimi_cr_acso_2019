# Monitoraggio e controllo processi

### Comando `ps`

Il comando `ps` permette di visualizzare lo stato e informazioni riguardo i processi
in esecuzione. Alcune opzioni utili:

- `a` per visualizzare processi di tutti gli utenti
- `x` per includere i processi che non hanno un terminale di riferimento (e.g. demoni)
- `u` per avere un output più user-friendly di default, oppure...
- `-o attr1,attr2,...` per specificare quali informazioni visualizzare

Exempio:

    $ ps au
    USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
    root         1  0.0  0.1 191576  9092 ?        Ss   13:22   0:01 /sbin/init splash
    root         2  0.0  0.0      0     0 ?        S    13:22   0:00 [kthreadd]
    root         3  0.0  0.0      0     0 ?        I<   13:22   0:00 [rcu_gp]
    root         4  0.0  0.0      0     0 ?        I<   13:22   0:00 [rcu_par_gp]
    ...

Per ulteriori informazioni:

    $ ps --help
    $ man ps

### Comando `htop`

Il comando `htop` permette di monitorare e controllare processi in tempo reale,
tramite una comoda interfaccia a riga di comando. Per avviare il programma:

    $ htop

Alcune informazione utili:

- Per uscire premere il tasto `q` o `F10`
- Premere il tasto `t` o `F5` per attivare la visualizzazione ad albero dei processi
- Utilizzare frecca su e giu per navigare nella lista di processi
- `F9` per inviare segnali al processo selezionato

### Comando `kill`

Tramite il comando `kill` è possibile inviare segnali ad un processo.

Per terminare un processo:

    $ kill -SIGTERM 1234
