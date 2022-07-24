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

    // Print the first 512 Bytes of the file
    char * data;
    fread(data, sizeof(*file_ptr), 1, file_ptr);

    printf("%s\n", data); 

    // Close the file
    fclose(file_ptr);
    
}