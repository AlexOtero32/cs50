#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool checksum(long number);
int get_length(long number);
int first_numbers(long number, int length);


int main(void)
{
    long number = get_long("Credit card number: ");

    int length = get_length(number);
    int first_number = first_numbers(number, length);

    // Does it comply with the Luhn's algorithm?
    if (! checksum(number))
    {
        printf("INVALID\n");

        return 0;
    }


    // Check if it is an American Express card
    if (length == 15 && (first_number == 34 || first_number == 37))
    {
        printf("AMEX\n");

        return 0;
    }

    // Check if it is a Mastercard card
    if (length == 16 && (first_number >= 51 && first_number <= 55))
    {
        printf("MASTERCARD\n");

        return 0;
    }

    // Check if it is a VISA card
    if ((length == 13 || length == 16) && (first_number / 10 == 4))
    {
        printf("VISA\n");

        return 0;
    }

    printf("INVALID\n");

}

// Luhn's algorithm
bool checksum(long number)
{
    int sum = 0;

    for (int i = 0; number != 0; i++, number /= 10)
    {
        if (i % 2 == 0)
        {
            sum += number % 10;
        }
        else
        {
            int doubled = 2 * (number % 10);

            // We add up the first and second digit of the result of doubling the digit
            sum += doubled / 10 + doubled % 10;
        }

    }

    return sum % 10 == 0;
}


// Gets the length of the number
int get_length(long number)
{
    int length;

    for (length = 0; number != 0; number /= 10)
    {
        length++;
    }

    return length;
}

// Gets the two first numbers
int first_numbers(long number, int length)
{
    return (int) trunc(number / (pow(10, length - 2)));
}