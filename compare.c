#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *x = get_string("x: ");
    printf("%c\n", *x);
}