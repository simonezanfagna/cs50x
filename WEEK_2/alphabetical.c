#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(void)
{
    string s = get_string("string: ");

    int lengthString = strlen(s);

    bool order = true;

    for (int i = 0; i < lengthString - 1; i++)
    {
        if (s[i] > s[i + 1])
        {
            order = false;
            break;
        }
    }


    if (order)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}

