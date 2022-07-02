#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask name
    string name = get_string("Hey what is your name?  ");
    // Print
    printf("hello, %s\n", name);
}