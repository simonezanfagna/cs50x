#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int size;
    do
    {
        size = get_int("Size: ");
    }
    while( size < 1 );

    int powerOfTwo[size];
    powerOfTwo[0]=1;

    for (int i = 0; i < size; i++)
    {
        powerOfTwo[i + 1] = 2 * powerOfTwo[i];
        printf("%i\n", powerOfTwo[i]);
    }
}

