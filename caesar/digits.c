#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool isdigit(string text);

int main(int argc, string argv[])
{
    // Check if an argument is digits
    if (isdigit(argv[1]))
    {
        printf ("All digits\n");
        return 0;
    }
    else
    {
        printf("Some are probably alphanumeric");
        return 1;
    }
}

bool isdigit(string text)
{
    int len_of_text = strlen(text);
    bool result = false;

    fot (int i = 0; i < len_of_text; i ++)
    {
        if (isdigit(text[i]))
        result = true;
    }
    else
    {
        result = false;
    }
    return result;
}