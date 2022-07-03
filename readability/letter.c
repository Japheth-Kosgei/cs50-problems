#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Take in a string and print out is len
    string text = get_string("Text: ");
    int len = strlen(text);

    printf("%i\n", len);
}