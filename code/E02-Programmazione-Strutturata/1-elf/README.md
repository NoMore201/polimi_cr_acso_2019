## ELF file format

Per generare un object file a partire da un file sorgente:

    gcc -c main.c
    gcc -c global.c

Compilare un programma a partire da object files:

    gcc -o main main.o global.o

Per visualizzare l'ELF header

    readelf -h main

Per visualizzare la lista di segmenti (Program Headers):

    readelf -l main

Per visualizzare la lista di sezioni (Section headers):

    readelf -S main

## Symbols

Ogni object file conterrà una tabella dei simboli relativi alla translation unit.
Per visualizzare i simboli all'interno di un object:

    nm main.o
    objdump -t main.o
