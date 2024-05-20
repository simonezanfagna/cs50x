// ogni volta che in c si vuole stampare qualcosa o fare un input output,
// si deve aggiungere questa libreria
#include <stdio.h>

// vedi https://manual.cs50.io/ per capire cosa puo' fare questa libreria
#include <cs50.h>

int main(void)
{
    string answer = get_string("What's your first name? ");
    string last = get_string("What's your last name? ");

    printf("hello, %s %s\n", answer,last);
}
