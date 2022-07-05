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
    int element_count = 0;

    for (int i = 0; i < key_length; i ++)
    {
        for (int j = 0; j < key_length; j ++)
        {
            if (key[j] == key[i])
            {
                element_count ++;
            }
        }

        if (element_count > 1)
        {
            printf("Key must not contain repeated characters.\n");
            element_count = 0;
            return 1;
        }
        element_count = 0;
    }

    // Prompt plaintext
    string plain_text = get_string("Plaintext:  ");
    int plain_text_length = strlen(plain_text);
    printf("ciphertext: ");

    for (int i = 0; i < plain_text_length; i ++)
    {
        // Upper case letters
        if (isupper(plain_text[i]))
        {
            char cipher_text_character = toupper(key[i]);
            printf("%c", cipher_text_character);
        }

        // Lower case letters
        else if (islower(plain_text[i]))
        {
            char cipher_text_character = tolower(key[i]);
            printf("%c", cipher_text_character);
        }

        // Anything else
        else
        {
            char cipher_text_character = plain_text[i];
            printf("%c", cipher_text_character);
        }
    }

    printf("\n");
}