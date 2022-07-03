#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Enter a character: ");
    int ascii_value = name[0];
    printf("The ASCII value is %i\n", ascii_value);
}