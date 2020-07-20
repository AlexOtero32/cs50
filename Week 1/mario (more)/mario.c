#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;

    // Ask for user input
    do
    {
        height = get_int("Height: ");
    }
    //Has to be more than 1 and less than 8
    while (height < 1 || height > 8);

    // Create a two dimensional grid with that value
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {

            // If the number of the row is more than or equal to the column + 1, we print a #
            if (i >= (height - (j + 1)))
            {
                printf("#");
            }
            // If not, we print a whitespace
            else
            {
                printf(" ");
            }
        }

        // Print the separator
        printf("  ");

        // Now, print out the opposite side
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }

        // We jump to a new line at the end of the row
        printf("\n");
    }
}