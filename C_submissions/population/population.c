#include <cs50.h>
#include <stdio.h>

int get_startSize(void);
int get_endSize(int startSize);
int calculateYears(int startSize, int endSize);

int main(void)
{
    // TODO: Prompt for start size

    int start = get_startSize();

    // TODO: Prompt for end size

    int end = get_endSize(start);

    // TODO: Calculate number of years until we reach threshold

    int years = calculateYears(start, end);

    // TODO: Print number of years

    printf("Years: %i \n", years);
}

int get_startSize(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    return n;
}

int get_endSize(int startSize)
{
    int n;
    do
    {
        n = get_int("End size: ");
    }
    while (n < startSize);
    return n;
}

int calculateYears(int startSize, int endSize)
{
    int years = 0;
    int population = startSize;

    while (population < endSize)
    {
        int born = population / 3;
        int passAway = population / 4;
        population = population + born - passAway;
        years++;
    }
    return years;
}
