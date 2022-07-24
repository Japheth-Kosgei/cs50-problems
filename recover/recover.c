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
    FILE * file_ptr = fopen(filename, "r");

    if (file_ptr == NULL)
    {
        printf("Error: File could not be opened.\n");
        return 2;
    }

    //
    char *character = malloc(sizeof(char) * 5);
    fread(character, 512, 1, file_ptr);

    printf("%s\n", character);

    // Close the file
    fclose(file_ptr);
    free(character);
}