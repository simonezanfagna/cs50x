#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Your name: ");
    int age =get_int("Your age: ");
    // long in questo caso va bene solo se uso numeri ma se voglio aggiungere
    // +39 per far capire che si tratta di un numero italiano per esempio,
    // allora non andrebbe piu' bene.
    /* long phoneNumber = get_long("Phone Number: "); */
    string phoneNumber = get_string("Phone Number: ");

    printf("%s %i %s\n",name, age, phoneNumber);
}

