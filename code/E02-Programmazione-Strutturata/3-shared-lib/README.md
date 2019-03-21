# Istruzioni

Compilare la shared library:

    $ gcc -shared -o libsample.so lib.c

Compilare il programma specificando la libreria:

    $ gcc -o main main.c -L. -lsample

*N.B.* in sistemi debian-based (ubuntu, linux mint ..) è necessario
specificare i parametri relativi alle shared libraries dopo i file sorgenti che
dipendono da tale libreria

- `-L.` indica al compilatore di aggiungere la directory
corrente alle directory in cui cercare le librerie shared
- `-lsample` indica al compilatore di linkare la libreria
lib*sample*.so che verra caricata durante lo startup

Eseguire il programma:

    $ LD_LIBRARY_PATH=. ./main

- `LD_LIBRARY_PATH` è una variabile d'ambiente utilizzata per indicare al compilatore
una lista di directory dove trovare le shared libraries
