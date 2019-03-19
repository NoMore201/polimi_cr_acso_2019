# Istruzioni

Generare la libreria statica:

    $ gcc -c lib.c
    $ ar rcs libsample.a lib.o

Compilare il programma specificando la libreria statica:

    $ gcc -o main main.c libsample.a

Eseguire il programma:

    $ ./main
