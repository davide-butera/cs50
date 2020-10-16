// Implements a dictionary's functionality
#define  _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 200000;
// Hash table
node *table[N];

unsigned int dict_size = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char lower[LENGTH] =  {0};
    int s = strlen(word);
    for (int i = 0; i <= s; i++)
    {
        lower[i] = tolower(word[i]);
    }
    int h = hash(lower);
    if (table[h] == NULL)
    {
        return false;
    }
    node *cursor = table[h];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, lower) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
// djb hash by Daniel J. Bernstein
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) ^ c;    // hash(i - 1) * 33 ^ str[i]
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *fp;
    if ((fp = fopen(dictionary, "r")) == NULL)
    {
        return false;
    }

    char word[LENGTH + 1] = {0};

    size_t len = 0;

    while (fscanf(fp, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        int pos = hash(word);
        n->next = table[pos];
        table[pos] = n;

        dict_size++;
    }

    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        node *cursor = table[i];
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}