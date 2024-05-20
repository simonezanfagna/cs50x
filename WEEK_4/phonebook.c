// QUESTO PROGRAMMA SALVA SU UN FILE I NUMERI E I NOMI
// PROPRIO COME UNA RUBRICA

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //  uso un file .csv perche' lo posso usare anche
    // in excel.

    // Open CSV file
    FILE *file = fopen("phonebook.csv", "a");
    if (!file)
    {
        return 1;
    }

    // Get name and number
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // Print to file
    fprintf(file, "%s,%s\n", name, number);

    // Close file
    fclose(file);
} 
