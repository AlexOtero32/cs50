#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Get the name from the user input
    string name = get_string("What is your name?\n");

    // Print the name formatted
    printf("Hello, %s!\n", name);
}