#include <cs50.h>
#include <stdio.h>

#define N 7

int main(void)
{
    // An array of integers
    int numbers[N] = {20, 500, 10, 5, 100, 1, 50};

    int temp;
    int index;

    for (int i = 0; i < N - 1; i++)
    {
        index = i;

        for (int k = i + 1; k < N; k++)
        {
            if (numbers[k] < numbers[index])
            {
                index = k;
            }
        }

        temp = numbers[i];
        numbers[i] = numbers[index];
        numbers[index] = temp;

    }

    for (int i = 0; i < N; i++)
    {
        printf("%i\n", numbers[i]);
    }
}
