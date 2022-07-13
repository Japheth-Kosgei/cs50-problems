#include <stdio.h>

int fact(int n);

int main(void)
{
    // Do a factorial
    printf("%i\n", fact(5));
}

int fact(int n)
{
    // Recursive function
    if (n == 1)
    {
        return 1;  // This is the end of the stack/loop, and it returns int 1; NOT an error.
    }

    return n * fact(n-1);  // This multiplies n by the return value of fact.
}