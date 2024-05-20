#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    int vote;
} candidate;

int main(void)
{
    const int num_candidates = 3;
    candidate candidates[num_candidates];

    candidates[0].name = "Pippo";
    candidates[0].vote = 100;

    candidates[1].name = "Pluto";
    candidates[1].vote = 1000;

    candidates[2].name = "Paperino";
    candidates[2].vote = 500;

    int highestVotes = 0;

    for (int i = 0; i < num_candidates; i++)
    {
        if (candidates[i].vote > highestVotes)
        {
            highestVotes = candidates[i].vote;
        }
    }

    for (int i = 0; i < num_candidates; i++)
    {
        if (candidates[i].vote == highestVotes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
