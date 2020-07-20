#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

bool isInteger(string argument);
string cipher(string plaintext, int key);

int main(int argc, string argv[])
{
    // Check if the number of arguments is 2 and the second argument is a number.
    if (argc != 2 || ! isInteger(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("plaintext: ");

    int key = atoi(argv[1]);

    key = key % 26;

    printf("ciphertext: %s\n", cipher(text, key));

}

// Is the second argument an integer?
bool isInteger(string argument)
{
    int i = 0;
    bool isInteger = true;

    // Until the end of the string
    while (argument[i] != '\0')
    {
        // Check if it is a digit
        if (!isdigit(argument[i]))
        {
            isInteger = false;
        }

        i++;
    }

    return isInteger;
}

// Cipher the text
string cipher(string plaintext, int key)
{
    int i = 0;

    // Iterate through the string
    while (plaintext[i] != '\0')
    {
        if (isupper(plaintext[i]))
        {
            // Calculate the offset if it is an uppercase character
            int offset = (plaintext[i] + key) % 65;

            if (offset >= 26)
            {
                offset -= 26;
            }

            plaintext[i] = offset + 65;
        }
        else if (islower(plaintext[i]))
        {
            // Calculate the offset if it is a lowercase character
            int offset = (plaintext[i] + key) % 97;

            if (offset >= 26)
            {
                offset -= 26;
            }

            plaintext[i] = offset + 97;
        }

        i++;
    }

    // Returns the ciphertext
    return plaintext;
}