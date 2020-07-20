#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float amount = 0;

    // Ask for a positive input
    do
    {
        amount = get_float("Money amount: ");
    }
    while (amount < 0);

    // Get the amount of cents
    int cents = round(amount * 100);

    int coins = 0;

    // Do the same thing until the change left is 0
    while (cents > 0)
    {
        // Check how much we can sustract
        if ((cents - 25) >= 0)
        {
            cents -= 25;
            coins++;
        }
        else if ((cents - 10) >= 0)
        {
            cents -= 10;
            coins++;
        }
        else if ((cents - 5) >= 0)
        {
            cents -= 5;
            coins++;
        }
        else
        {
            cents--;
            coins++;
        }
    }

    // Print the number of coins
    printf("%i\n", coins);
}