#include <stdio.h>
#include <cs50.h>
#include <string,h>

int main()
{
    // In case you forget, find the length of a string(array of characters)
    // Get string
    string name_string = get_string("Enter your name: ");

    // Find the number of characters in the string
    int len = get_string_length(name_string);
    printf("%i\n", len);
}