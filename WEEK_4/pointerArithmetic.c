#include <stdio.h>

int main(void)
{
    char *s = "HI!";

    printf("%c\n", s[2]);

    printf("%c\n", *(s + 1));
}
