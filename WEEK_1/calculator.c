#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long x = get_long("x: ");
    long y = get_long("y: ");

    // trasformo x e y da interi a float in modo che il risultato
    // tenga in considerazione anche i numeri dopo la virgola
    // ma uso double in modo da avere, rispetto a float, piu' bit
    // a disposizione per la parte dopo la virgola.
    double z = (double) x / (double) y;

    // devo inserire un .valore nel %f per stampare un type float (decimale)
    // con un preciso numero di cifre decimali
    printf("%.20f \n", z);
}
