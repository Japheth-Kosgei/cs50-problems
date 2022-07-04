#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check if the arguement count is one, not less, not more
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./substituion KEY\n");
        return 1;
    }

    // Check if key is valid: not containing non-alhpabetic letters, 26 letters, each letter should appear only once.
    string key = argv[1];
    int key_length = strlen(key);

    // Check if key has 26 letters
    if (key_length != 26)
    {
        printf("Key must have 26 characters.\n");
        return 1;
    }

    // Check if all characters are alphabetical
    for (int i = 0; i < key_length; i ++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain alphabetical characters only.\n");
            return 1;
        }
    }

    // Check if the key contain only one of each alphabets
    for (int i = 0; i < key_length; i ++)
    {
        for (int j = 0; j < key_length;)
    }

    // Change the key to all-uppercase
    // Print plaintext
    // Print ciphertext
    // Encrypt
    // Exit.
}