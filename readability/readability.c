#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    // Prompt the user for text
    string text = get_string("Text: ");

    // Count the number of letters
    int number_letters = count_letters(text);
    printf("%i\n", number_letters);

    // Count the number of words

    // Count the number of sentences

}

int count_letters(string text)
{
    int length_of_string = strlen(text);
    int number_letters = 0;

    for (int i = 0; i < number_letters; i++)
    {
        
    }
}