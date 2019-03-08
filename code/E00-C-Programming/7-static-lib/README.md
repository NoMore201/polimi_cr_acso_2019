# Istruzioni

Compilare la shared library:

    $ gcc -shared -o libsample.so lib.c

Compilare il programma specificando la libreria:

    $ gcc -o main -L. -lsample main.c

- `-L.` indica al compilatore di aggiungere la directory
corrente alle directory in cui cercare le librerie
- `-lsample` indica al compilatore di utilizzare la libreria
lib*sample*.so in fase di linking

Eseguire il programma:

    $ LD_PRELOAD=./libsample.so ./main
