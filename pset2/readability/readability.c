#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int coleman_liau_index(int l, int s, int w);

int main(void)
{
    string s = get_string("Text: ");

    int letters = 0, words = 1, sentences = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isupper(s[i]) || islower(s[i]))
        {
            letters++;
        }
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
        else if (s[i] == ' ')
        {
            words++;
        }
    }

    int index = coleman_liau_index(letters, sentences, words);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int coleman_liau_index(int l, int s, int w)
{
    /*
    L: average number of letters per 100 words
    S: average number of sentences per 100 words
    */
    float L = (float) l * 100 / (float) w;
    float S = (float) s * 100 / (float) w;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    return round(index);
}