#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_positive_float(void);

int main(void)
{
    /*initializes everything to zero*/
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;

    /*takes the input in dollars and converts it to cents*/
    float dollars = get_positive_float();
    int cents = round(dollars * 100);
    
    /*the actual math*/
    quarters = cents / 25;
    cents = cents - quarters * 25;
    dimes = cents / 10;
    cents = cents - dimes * 10;
    nickels = cents / 5;
    cents = cents - nickels * 5;
    pennies = cents;

    //printf("%i,%i,%i,%i\n", quarters, dimes, nickels, pennies);
    printf("%i\n", quarters + dimes + nickels + pennies);
}

/*gets a float and check if it's positive*/
float get_positive_float(void)
{
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n <= 0);
    return n;
}