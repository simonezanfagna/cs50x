#include <cs50.h>
#include <stdio.h>
/*
The Collatz conjecture is applies to positive integers and
speculates that it is always possible to get “back to 1” if you
follow these steps:
• If n is 1, stop.
• Otherwise, if n is even, repeat this process on n/2.
• Otherwise, if n is odd, repeat this process on 3n + 1.
• Write a recursive function collatz(n) that calculates how
many steps it takes to get to 1 if you start from n and recurse
as indicated above.
 */
int collatz(int number);
int main(void)
{
    int number;

    do
    {
        number = get_int("Number: ");
    }
    while (number < 0);

    printf("Steps: %i\n", collatz(number));
}

int collatz(int number)
{

    if (number == 1)
    {
        return 0;
    }
    else if ((number % 2) == 0 )
    {
        return 1 + collatz(number / 2);
    }
    else
    {
        return 1 + collatz(3 * number + 1);
    }
}
/*
collatz(4) => return 1 + collatz(2)
collatz(2) => return 1 + collatz(1)
collatz(1) => return 0
quindi collatz(1) = 0,
allora collatz(2) => return 1 quindi collatz(2) = 1,
allora collatz(4) => return 2 quindi collatz(4) = 2,
totale 2 steps
 */
