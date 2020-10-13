#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool is_valid_int(string s);
string encrypt(string plaintext, int key);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!is_valid_int(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    printf("key: %i\n", key);

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: %s\n", encrypt(plaintext, key));

}

bool is_valid_int(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

string encrypt(string plaintext, int key)
{
    string encrypted = plaintext;
    for (int i = 0, n = strlen(encrypted); i < n; i++)
    {
        if (islower(encrypted[i]))
        {
            encrypted[i] = ((encrypted[i] - 'a' + key) % 26) + 'a';
        }
        else if (isupper(encrypted[i]))
        {
            encrypted[i] = ((encrypted[i] - 'A' + key) % 26) + 'A';
        }
    }
    return encrypted;
}
