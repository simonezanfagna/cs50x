#include <stdio.h>

int main(void)
{
    // evitare di non assegnare valori ad un blocco di memoria o varibili.
    int scores[1024];
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}
