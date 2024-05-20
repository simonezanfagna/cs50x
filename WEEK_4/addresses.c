#include <stdio.h>

int main(void)
{
    int n = 50;

    int *p = &n;

    // stampa l'indirizzo
    printf("%p\n", p);

    // stampa il valore che si trova a quell'indirizzo
    printf("%i\n", *p);
}
