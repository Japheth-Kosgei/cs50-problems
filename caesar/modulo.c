#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // Find out what modulo does
    int a = get_int("a: ");
    int b = get_int("b: ");

    int modulo = a % b;
    printf("Modulo = %i\n", modulo);
}