# Istruzioni

Compilare la shared library:

    $ gcc -shared -o libsample.so lib.c

Compilare il programma:

    $ gcc -o main main.c -ldl

- `-ldl` indica al compilatore di linkare la libreria di sistema
lib*dl*.so

Eseguire il programma:

    $ ./main ./libsample.so
