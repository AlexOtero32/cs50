#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool isValidKey(string key);
string cipher(string key, string text);


int main(int argc, string argv[])
{
    // It has to have exactly 2 elements
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // if it is not valid we reject
    if (!isValidKey(key))
    {
        printf("The key is not valid!\n");
        return 1;
    }

    // Take the input string
    string text = get_string("plaintext: ");

    // Print out the output string
    printf("ciphertext: %s\n", cipher(key, text));

}

bool isValidKey(string key)
{
    int i = 0;

    // It is not valid if it contains any non-alphabetical character
    while (key[i] != '\0')
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        // Check if there is any repeated character
        for (int j = 0; j < strlen(key); j++)
        {

            if (tolower(key[i]) == tolower(key[j]) && i != j)
            {
                return false;
            }
        }

        i++;
    }

    // It is not valid if it doesn't contain 26 letters
    if (i != 26)
    {
        return false;
    }

    return true;
}

string cipher(string key, string text)
{
    int i = 0;

    // Iterate through the plain text
    while (text[i] != '\0')
    {
        if islower(text[i])
        {
            // Change lowercase letters for the one in its position in the array
            int offset = text[i] - 97;
            text[i] = tolower(key[offset]);
        }
        else if (isupper(text[i]))
        {
            // Same with uppercase letters
            int offset = text[i] - 65;
            text[i] = toupper(key[offset]);
        }

        // Ignore no uppercase or lowercase (every non-alphabetical character)

        i++;
    }

    return text;
}