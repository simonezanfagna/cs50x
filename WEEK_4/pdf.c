// di solito i file hanno 4 byte all'inizio che rappresentano che tipo di
// file si tratta, ogni byte rappresenta un numero.
// ad esempio un file pdf, all'inizio, ha quattro byte che corrispondono
// a 4 numeri interi : 37, 80, 68, 70

// questo programma controlla se un file e' un pdf
#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    string fileName = argv[1];

    FILE *file = fopen(fileName, "r");

    // creo un buffer dove memorizzare 4 numeri positivi e ogni numero occupa un byte
    uint8_t buffer[4];

    fread(buffer, 1, 4, file);

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
    }

    fclose(file);
}
