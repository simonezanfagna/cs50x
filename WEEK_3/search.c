#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // An array of integers
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    // Search for number
    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0; // in questo modo stoppa il programma quando trova il numero
        }
    }
    printf("Not found\n");
    return 1; // serve solo da controllo, per indicare che il programma non ha trovato il numero
}
