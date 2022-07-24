#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_jpeg(char * array, int len);

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

    char *buffer = malloc(512);
    while (true)
    {
        // Read 512-byte blocks of the data
        if ((fread(buffer, 512, 1, mem_card)) < 1)
        {
            break;
        }

        // Check whether the buffer is a JPEG
        if (is_jpeg(buffer, 4))

    // Free the buffer
    free(buffer);

    // Close the file
    fclose(mem_card);
}

bool is_jpeg(char * array, int len)
{
    // Return true if the buffer is JPEG
    if (
        array[0] == 0xff &&
        array[1] == 0xd8 &&
        array[2] == 0xff &&
        array[3] == 
    )
}