#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // Find out what modulo does
    int plain_text_char = get_int("plain_text_char: ");
    int key = get_int("key:  ");
    int answer = (plain_text_char + key);

    printf("Answer is %i\n", answer);
}