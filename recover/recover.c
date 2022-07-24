#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Ensure only one command-line argument is given
    if (argc != 2)
    {
        printf("Usage: recover <filename>\n");
        return 1;
    }

    // Open the file
    char * filename = argv[1];
    FILE * mem_card = fopen(filename, "r");

    if (mem_card == NULL)
    {
        printf("Error: File could not be opened.\n");
        return 2;
    }

    while (true)
    {
        // Read 512-byte blocks of the data
        char *buffer = malloc(512);

        // Free the buffer
        free(buffer);
    }

    // Close the file
    fclose(mem_card);
}