#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");

    printf("After: ");

    int lengthString = strlen(s);

    for (int i = 0; i < lengthString; i++)
    {

        printf("%c", toupper(s[i]));
    }

    printf("\n");
}
