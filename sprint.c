#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Make an series of strings from 000 to 999 and print
    int number_of_image = 0;
    char * filename = malloc(8);
    filename = "000.jpg";
    printf("%s\n", filename);

    for (int i = 1; i < 1000; i ++)
    {
        sprintf(filename, "%3i", i);
        printf("%s\n", filename);
    }

    free(filename);
}
