#include <stdio.h>

int main(void)
{
    int n = 5; // The content
    int *pn = &n; // The pointer of int n
    printf("%p\n", pn); // Print the pointer
    printf("%i\n", *pn); // Print the value of the pointer.
}