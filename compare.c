#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    if (x == y)
    {
        printf("Similar\n");
        return 0;
    }

    printf("Different\n");
}