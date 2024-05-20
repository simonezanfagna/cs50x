#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Your name: ");

    int n = strlen(name);

    printf("%i\n", n);
}

