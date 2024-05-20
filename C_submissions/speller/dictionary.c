// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

unsigned int dSize = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index_word = hash(word);

    node *n = table[index_word];

    while (n != NULL)
    {
        if (strcasecmp(n->word, word) == 0)
        {
            return true;
        }

        n = n->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value = hash_value * 31 + tolower(word[i]);
    }
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file_dictionary = fopen(dictionary, "r");

    char new_word[LENGTH + 1];

    while (fscanf(file_dictionary, "%s", new_word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            fclose(file_dictionary);
            return false;
        }

        strcpy(n->word, new_word);

        int index_word = hash(new_word);

        n->next = table[index_word];

        table[index_word] = n;

        dSize++;
    }

    fclose(file_dictionary);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dSize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        node *ptr = NULL;

        while (n != NULL)
        {
            ptr = n->next;
            free(n);
            n = ptr;
        }
        table[i] = NULL;
    }
    return true;
}
