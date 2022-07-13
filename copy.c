#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // copy content from one variable to another
    char *s = get_string("x: ");
    char x = s[0];
    char y = x;
    printf("%c\n", x);
    printf("%c\n\n", y);

    // Make it upper to know if it copied correctly
    y = toupper(x);
    printf("%c\n", x);
    printf("%c\n", y);
}