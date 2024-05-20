#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // An array of strings
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    // Search for string
    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        // per comparare due stringhe in c si usa la funzione "strcmp" inclusa nella libreria string.h
        // questa funzione fa restituisce 0 se le stringhe sono uguali
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
