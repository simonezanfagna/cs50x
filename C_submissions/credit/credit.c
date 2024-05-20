#include <cs50.h>
#include <stdio.h>

int checkCardLength(long cardNumber);
int luhnAlgorithm(long cardNumber);
void checkBrand(long cardNumber, int cardLength);

int main(void)
{
    long cardNumber = get_long("Number: ");
    int cardLength = checkCardLength(cardNumber);

    if (cardLength == 13 || cardLength == 15 || cardLength == 16)
    {
        int checkSum = luhnAlgorithm(cardNumber);

        if (checkSum == 0)
        {
            checkBrand(cardNumber, cardLength);
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int checkCardLength(long cardNumber)
{
    long card = cardNumber;

    int i = 0;
    while (card > 0)
    {
        card = card / 10;
        i++;
    }

    return i;
}

int luhnAlgorithm(long cardNumber)
{
    long card = cardNumber;
    int sum_1 = 0;
    int sum_2 = 0;

    int module_sum_2;

    while (card > 0)
    {
        sum_1 += card % 10;
        card = card / 10;

        module_sum_2 = card % 10 * 2;
        sum_2 = (module_sum_2 / 10) + (module_sum_2 % 10) + sum_2;
        card = card / 10;
    }

    int sum = sum_1 + sum_2;

    int sum_lastDigit = sum % 10;

    return sum_lastDigit;
}

void checkBrand(long cardNumber, int cardLength)
{
    long card = cardNumber;

    long k = 1;

    for (int i = 0; i < (cardLength - 2); i++)
    {
        k = k * 10;
    }

    int firstAndSecondDigits = card / k;
    int firstDigit = firstAndSecondDigits / 10;

    if (cardLength == 16 && (firstAndSecondDigits >= 51 && firstAndSecondDigits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if (cardLength == 15 && (firstAndSecondDigits == 34 || firstAndSecondDigits == 37))
    {
        printf("AMEX\n");
    }
    else if ((cardLength == 13 || cardLength == 16) && firstDigit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
