#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int height);

int main(void)
{
    int height = get_height();
    print_pyramid(height);
}

int get_height(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void print_pyramid(int height)
{
    int initialSpace = height - 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int spaceLeft = initialSpace;
            if (spaceLeft <= j)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }

            spaceLeft--;
        }

        printf("  ");

        for (int k = 0; k < height; k++)
        {
            int spaceRight = initialSpace;
            int hash = height - spaceRight;
            if (hash > k)
            {
                printf("#");
            }

            spaceRight--;
        }

        initialSpace--;
        printf("\n");
    }
}
