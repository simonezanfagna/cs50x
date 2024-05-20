#include <cs50.h>
#include <stdio.h>

const int N = 3;

float avarage(int array[], int length);

int main(void)
{
    int scores[N];

    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Scores: ");
    }

    printf("Avarage: %f\n", avarage(scores, N));
}

float avarage(int array[], int length)
{
    int sum = 0;

    for (int k = 0; k < length; k++)
    {
        sum += array[k];
    }

    return sum / (float) length;
}
