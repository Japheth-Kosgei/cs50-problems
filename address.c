#include <stdio.h>

int main(void)
{
    char *s = "Hi!";
    printf("%p\n", s); // Print the pointer of s
    printf("%c\n", *s); // Print the content of s
}