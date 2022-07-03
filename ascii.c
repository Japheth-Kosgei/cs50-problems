#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    //This function takes in a character and prints out its ASCII value.
    string name = argv[1];
    char character = name [0];
    int ascii_value = character;
    printf("%i\n", ascii_value);
}