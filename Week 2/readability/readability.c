#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");

    // Iterator
    int i = 0;


    // Number of letters
    int letters = 0;

    // Number of words
    // We have to initialize at 1, because a one word sentence has no space before nor after.
    int words = 1;

    // Number of sentences
    int sentences = 0;

    while (text[i] != '\0')
    {
        if (text[i] >= 'A' && text[i] <= 'z')
        {
            letters++;
        }

        if (text[i] == ' ')
        {
            words++;
        }

        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }

        i++;
    }

    double L = (100.00 * letters) / words;
    double S = (100.00 * sentences) / words;

    double index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        int grade = round(index);
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }



}