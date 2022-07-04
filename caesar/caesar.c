#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_digits_only(string plain_text);

int main(int argc, string argv[])
{
    // Accept input
    // Check if it has more than or less than 2 args
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the plain_text is only decimal digit; and print an error meassage
    if (is_digits_only(argv[1]))
    {
        return 0;
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Do the encryption
        // For each character in the plaintext
            // If it is a lower case character;
                // Rotate using k
            // If it is upper case
                // Rotate using but differently

    // Print the ciphertext
}

bool is_digits_only(string plain_text)
{
    bool result = false;
    int length_of_plain_text = strlen(plain_text);
    for (int i = 0; i < length_of_plain_text; i ++)
    {
        if (isdigit(plain_text[i]))
        {
            result = true;
        }

        else
        {
            result = false;
        }
    }

    return result;
}