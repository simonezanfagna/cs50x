#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int checkPrompt(string prompt[], int argc);

int main(int argc, string argv[])
{

    int status = checkPrompt(argv, argc);

    if (status == 0)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (status == 1)
    {
        printf("Usage %s key\n", argv[0]);
        return 1;
    }
    else
    {
        string key = argv[1];

        string plaintext = get_string("plaintext: ");

        int lengthPlaintext = strlen(plaintext);

        char c;
        for (int i = 0; i < lengthPlaintext; i++)
        {
            c = plaintext[i];
            if (isalpha(c))
            {
                if (islower(c))
                {
                    plaintext[i] = tolower(key[plaintext[i] - 97]);
                }
                else
                {
                    plaintext[i] = toupper(key[plaintext[i] - 65]);
                }
            }
        }

        printf("ciphertext: %s\n", plaintext);
        return 0;
    }
}

int checkPrompt(string prompt[], int argc)
{
    int status = 2;

    if (argc != 2)
    {
        status = 1;
    }
    else
    {
        int lengthKey = strlen(prompt[1]);
        string key = prompt[1];
        char c;

        if (lengthKey != 26)
        {
            status = 0;
        }

        for (int i = 0; i < lengthKey; i++)
        {
            c = tolower(key[i]);
            if (c < 'a' || c > 'z')
            {
                status = 1;
            }
        }

        for (int k = 0; k < lengthKey; k++)
        {
            for (int j = 0; j < lengthKey; j++)
            {
                if (k != j)
                {
                    if (tolower(key[k]) == tolower(key[j]))
                    {
                        status = 1;
                    }
                }
            }
        }
    }

    return status;
}
