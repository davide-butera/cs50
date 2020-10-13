#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /*gets the name of the user*/
    int n = 0;
    do
    {
        n = get_int("Height: ");
    } 
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        //for every line, spaces = height - current line - 1
        for (int j = n - i - 1; j > 0; j--)
        {
            printf(" ");
        }
        //hashes are just printed after spaces
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}