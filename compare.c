#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *x = get_string("x: ");
    char *y = get_string("y: ");

    if (*x == *y)
    {
        printf("Similar\n");
        return 0;
    }

    printf("Different\n");
}