#include <cs50.h>
#include <stdio.h>

int factorial(int number);
int main(void)
{
    int number;

    do
    {
        number = get_int("Number: ");
    }
    while (number < 0);

    printf("Factorial: %i\n", factorial(number));
}

int factorial(int number)
{

    if (number <= 1)
    {
        return 1;
    }

    // senza la recursive fanction
    /*
    int partialResult = 1;

    for (int i = number - 1; i >= 1; i--)
    {
        partialResult *= i;
    }

    return number * partialResult;
     */

    // con recursive function
    return number * factorial(number - 1);
}
