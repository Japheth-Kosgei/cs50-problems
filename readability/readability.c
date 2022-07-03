#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);

int main(void)
{
    // Prompt the user for text
    string text = get_string("Text: ");

    // Count the number of letters
    int number_letters = count_letters(text);
    printf("%i letters\n", number_letters);

    // Count the number of words
    int number_words = count_words(text);
    printf("%i words\n", number_words);

    // Count the number of sentences

}

int count_letters(string text)
{
    // Count the number of lower and upper case letters, not punctuations, etc.
    int length_of_string = strlen(text);
    int number_letters = 0;

    for (int i = 0; i < length_of_string; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            number_letters ++;
        }
    }

    return number_letters;
}

int count_words(string text)
{
    // Count the number of words in the text (a sequence of letters seperated by a space)
    int number_words = 1; //This is to account for the last word without space.
    int length_of_string = strlen(text);

    for (int i = 0; i < length_of_string; i++)
    {
        if (text[i] == ' ')
        {
            number_words ++;
        }
    }

    return number_words;
}
