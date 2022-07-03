#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for text
    string text = get_string("Text: ");

    // Count the number of letters
    int number_letters = count_letters(text);

    // Count the number of words
    int number_words = count_words(text);

    // Count the number of sentences
    int number_sentences = count_sentences(text);

    // Calculate the Coleman-Liau index
    float L = ((float)number_letters / number_words) * 100;
    float S = ((float)number_sentences / number_words) * 100;
    float premature_index = 0.0588 * L - 0.296 * S -15.8;
    double index = round(premature_index);

    if (index < 1)
    {
        printf("\nBefore Grade 1\n\n");
    }
    else if (index >= 16)
    {
        printf("\nGrade 16+\n\n");
    }
    else
        printf("\nGrade %i\n\n", (int)index);
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

int count_sentences(string text)
{
    // Count the number of sentences seperated by . or ! or ?
    int number_sentences = 0;
    int length_of_string = strlen(text);

    for (int i = 0; i < length_of_string; i ++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        number_sentences ++;
    }

    return number_sentences;
}
