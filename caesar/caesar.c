#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool is_digits_only(string plain_text);
char rotate(char plain_text_char, int key);

int main(int argc, string argv[])
{
    // Check if it has more than or less than 2 args
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the plain_text is only decimal digit; and print an error meassage
    if (!is_digits_only(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] to int
    int key = atoi(argv[1]);
    string plain_text = get_string("plaintext: ");
    int len_plain_text = strlen(plain_text);

    // Do the cipher
    printf("ciphertext: ");
    for (int i = 0; i < len_plain_text; i ++)
    {
        char cipher_text_char = rotate(plain_text[i], key);
        printf("%c", cipher_text_char);
    }

    printf("\n");
}


bool is_digits_only(string plain_text)
{
    // Check if it has had decimal digits only
    bool result = false;
    int length_of_plain_text = strlen(plain_text);

    // Loop through the string
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


char rotate(char plain_text_char, int key)
{
    // Rotate the plain_text_char by the key
    char cipher_text_char = plain_text_char;

    // Upper case letters
    if (isupper(plain_text_char))
    {
        plain_text_char -= 65;
        cipher_text_char = (plain_text_char + key) % 26;
        cipher_text_char += 65;
    }

    // Lower case letters
    if (islower(plain_text_char))
    {
        plain_text_char -= 97;
        cipher_text_char = (plain_text_char + key) % 26;
        cipher_text_char += 97;
    }

    return cipher_text_char;
}