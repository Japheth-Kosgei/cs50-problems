#include <stdio.h>
#include <cs50.h>

int main()
{
    // In case you forget, find the length of a string(array of characters)
    // Get string
    string name = get_string("Enter your name: ");

    // Find the number of characters in the string
    int length = 0;
    while (name[length] != 0)
    {
        length ++;
    }
    printf("%i\n", length);
}