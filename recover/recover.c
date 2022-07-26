#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;

int BLOCK_SIZE = 512;

bool is_jpeg(BYTE * array);

int main(int argc, char *argv[])
{
    // Ensure only one command-line argument is given
    if (argc != 2)
    {
        printf("Usage: recover IMAGE\n");
        return 1;
    }

    // Open the memory card
    FILE * mem_card = fopen(argv[1], "r");

    if (mem_card == NULL)
    {
        printf("Error: File could not be opened.\n");
        return 2;
    }


    BYTE * buffer = malloc(512); // Buffer is an array of bytes
    char * filename = malloc(8);
    sprintf(filename, "%03i.jpg", 0); // First image
    bool already_found_jpeg = false;
    int number_of_image = 0;
    FILE * image = fopen(filename, "w");

    // Loop through the image in 512 B chunks
    // Read 512-byte blocks of the data
    while (fread(buffer, 1, BLOCK_SIZE, mem_card) == BLOCK_SIZE)
    {

        // Allocate memory for the filename of the image

        // Check whether the buffer is a JPEG
        if (is_jpeg(buffer))
        {
            // Make already_found_jpeg true, if not already true. If false then it means this is the first jpeg
            if(already_found_jpeg == false)
            {
                fwrite(buffer, 1, BLOCK_SIZE, image);
                already_found_jpeg = true;
            }

            else // This is not the first jpeg block.
            {
                // Close the file that I have been working on in the last iteration
                fclose(image);

                // Open a new jpeg file and write into it.
                number_of_image ++;
                sprintf(filename, "%03i.jpg", number_of_image);
                image = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, image);
            }
        }

        else
        {
            if (already_found_jpeg == true)
            {
                // Write data to the existing open file
                fwrite(buffer, 1, BLOCK_SIZE, image);
            }
        }
    }

    // Close the file on the last iteration
    fclose(image);
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

    else
    {
        return false;
    }
}