#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float L = (float) count_letters(text) / (float) count_words(text) * 100;
    float S = (float) count_sentences(text) / (float) count_words(text) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int roundedIndex = round(index);
    if (roundedIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else if (roundedIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", roundedIndex);
    }
}

int count_letters(string text)
{
    int lengthText = strlen(text);

    char c;
    int numberOfLetters = 0;
    for (int i = 0; i < lengthText; i++)
    {
        c = tolower(text[i]);
        if (c >= 'a' && c <= 'z')
        {
            numberOfLetters++;
        }
    }

    return numberOfLetters;
}

int count_words(string text)
{
    int lengthText = strlen(text);

    int numberOfWords = 0;

    for (int i = 0; i <= lengthText; i++)
    {
        if ((text[i] == ' ' && text[i - 1] != ' ') || text[i] == '\0')
        {
            numberOfWords++;
        }
    }

    return numberOfWords;
}

int count_sentences(string text)
{
    int lengthText = strlen(text);

    int numberOfSentences = 0;

    for (int i = 0; i < lengthText; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            numberOfSentences++;
        }
    }

    return numberOfSentences;
}
