#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{

    // se dopo il nome del programma viene scritta solo un'altra parola,
    // quindi agrc e' uguale a 2 poiche' contiene il nome del prgramma e la parola scritta,
    // stampo la parola scritta
    if (argc == 2)
    {
        printf("Hello, %s\n", argv[1]);
    }
    // se scrio piu' cose oppure niente, allora stampo Hello world
    else
    {
        printf("Hello, world\n");
    }

}
