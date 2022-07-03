#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Enter a character: ");
    printf("The ASCII value is %d\n", name[0]);
}