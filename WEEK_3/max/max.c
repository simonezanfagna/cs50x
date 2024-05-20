// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int temp_max_index;
    int temp_max;

    if (n==1)
    {
        return array[0];
    }

    for (int i = 0; i < n - 1; i++)
    {
        temp_max_index = i;
        if (array[temp_max_index] > array[i + 1])
        {
            temp_max = array[temp_max_index];
        }
    }

    return temp_max;
}
