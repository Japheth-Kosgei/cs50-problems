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

    bool end_of_file = false;
    char *buffer = malloc(512);
    while (end_of_file == false)
    {
        // Read 512-byte blocks of the data
        fread(buffer, 5, 1, mem_card);
        for (int i = 0; i < 5; i ++)
        {
            if (buffer[i] == EOF)
            {
                end_of_file = true;
            }
        }

        printf("%s", buffer);
        // Free the buffer
    }
    free(buffer);

    // Close the file
    fclose(mem_card);
}