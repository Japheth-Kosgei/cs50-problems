#include <cs50.h>
#include <stdio.h>

float is_digits_only(string plain_text);

int main(int argc, string argv[])
{
    // Accept input
        // Return 1 if:
            // If it doesn't have a commandline argument
            // It has more then one command line argument
            // It is not a decimal digit; and print an error meassage

    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        return 0;
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
    int length_of_plain_text = strlen(plain_text);
    for (int i = 0; i < length_of_plain_text; i ++)
    {
        if (isalnum(plain_text))
        {
            return true;
        }

        else
        {
            return false;
        }
    }
}