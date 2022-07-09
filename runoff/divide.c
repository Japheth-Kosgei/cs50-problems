#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Find out the result of dividing two numbers using /
    int x = get_int("X: ");
    int y = get_int("Y: ");
    int answer = x / y;
    printf("Answer: %i\n", answer);
}