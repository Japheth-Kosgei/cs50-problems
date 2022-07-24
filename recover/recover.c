#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint>
#include <string.h>

typedef uint8_t BYTE;

bool is_jpeg(BYTE * array);

int main(int argc, char *argv[])
{
    // Ensure only one command-line argument is given
    if (argc != 2)
    {
        printf("Usage: recover IMAGE\n");
        return 1;
    }

    // Open the file
    FILE * mem_card = fopen(argv[1], "r");

    if (mem_card == NULL)
    {
        printf("Error: File could not be opened.\n");
        return 2;
    }


    // Loop through the image in 512 B chunks
    BYTE *buffer = malloc(512); // Buffer is an array of bytes
    while (true)
    {
        // Read 512-byte blocks of the data
        if ((fread(buffer, 512, 1, mem_card)) < 1) // fread returns a number less then one if EOF is reached or an error occurs
        {
            break;
        }

        // Allocate memory for the filename of the image
        char * filename = malloc(4);
        int number_of_image = -1;

        // Check whether the buffer is a JPEG
        if (is_jpeg(buffer))
        {
            // Create a new file for writing the jpeg to
            // If it is the first jpeg file(image 000)
            if (strcmp("000.jpg", filename) != 0)
            {

            }
            number_of_image ++;
            sprintf(filename, "%3i.jpg", 1)
            FILE * image = fopen(filename, "w");

            // Write the jpeg
            fwrite(buffer, 512, 1, image);
        }

        else
        {
            fwrite(buffer, 512, 1, image);
        }
    }

    // Free the buffer
    free(buffer);
    // Free the filename memory
    free(filename);

    // Close the file
    fclose(mem_card);
}

bool is_jpeg(BYTE * array) // Take in an array of bytes
{
    // Return true if the buffer is JPEG
    if (
        array[0] == 0xff &&
        array[1] == 0xd8 &&
        array[2] == 0xff &&
        (array[3] & 0xf0) == 0xe0
    )
    {
        return true;
    }
}