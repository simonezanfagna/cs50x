#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!";

    // stampa l'indirizzo
    printf("%p\n", s);

    // in questo caso aggiungo & per conoscere l'indirizzo
    // di quel carattere specifico.
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}
