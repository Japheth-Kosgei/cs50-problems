#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "Hi!";
    printf("%p\n", s); // Print the pointer of s
    printf("%c\n", *s); // Print the content of s
    printf("%c\n", *(s + 1));
}