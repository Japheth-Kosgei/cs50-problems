// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 17576;

// Hash table
node *table[N];

// Size of the dictionary
unsigned int DICT_SIZE = 0;



// Recursive function to return true if word is in dictionary
// Takes in the head of the linked list and the word in question
bool word_exists(node * head, const char * word)
{
    // Traversal pointer
    node * trav = head;

    if (strcasecmp(trav->word, word) == 0)
    {
        return true;
    }

    else
    {
        if (trav->next == NULL)
        {
            return false;
        }

        else
        {
            trav = trav->next;
            return word_exists(trav, word);
        }

    }
}




// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // // TODO
    // Hash the word
    int hash_value = hash(word);

    // Check if there is data in table[hash_value]
    if (table[hash_value] == NULL)
    {
        return false;
    }

    // Keeps track of the head of the linked list
    node * head = table[hash_value];  /////TODO Something is wrong here.

    if (word_exists(head, word))
    {
        return true;
    }


    return false;
}




// Hashes word to a number
unsigned int hash(const char *word)
{
    // // TODO: Improve this hash function
    // return tolower(word[0]) - 'a';

    // Count the number of letters in the word.
    int len = 0;
    for (int i = 0; i < strlen(word); i ++)
    {
        if (isalpha(word[i]))
        {
            len ++;
        }
    }


    // Begin hashing
    // One-letter-word.
    if (len == 1)
    {
        return (tolower(word[0]) - 97);
    }

    // Two-letter-word.
    else if (len == 2)
    {
        return ((tolower(word[0]) - 97) * 26) + (tolower(word[1]) - 97);
    }

    // If the word has three or more letters.
    else
    {
        return (((tolower(word[0]) - 97) * 676) + (tolower(word[1]) - 97) * 26) + (tolower(word[2]) - 97);
    }
}






// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file.
    FILE *dict = fopen(dictionary, "r");

    // Make sure that the file opened successfully.
    if (dict == NULL)
    {
        return false;
    }

    char *word = malloc(LENGTH + 1);
    while(fscanf(dict, "%s", word) != EOF)  // Read the contents of the dictionary, word by word.
    {
        node * node_ptr = malloc(sizeof(node));
        if (node_ptr == NULL)
        {
            return false;
        }

        // Copy the word from the dictionary to memory(node_ptr)
        strcpy(node_ptr->word, word);

        // Get the hash
        int index = hash(node_ptr->word);
        if (table[index] == NULL)  // If the table[index] does not already have a node
        {
            node_ptr->next = NULL;
            table[index] = node_ptr;

            // Check if it was successful
            if (table[index] == NULL)
            {
                return false;
            }
        }

        else  // If the table[index] already has a node
        {
            // The content of table[index] is the head pointing to the first node.
            // node_ptr is the new node
            // It should point to the first node in that table[index] was initially pointing to.
            node_ptr->next = table[index];

            // Reset head to point to the new pointer
            table[index] = node_ptr;

            // Ensure that it was successful
            if (table[index] == NULL || table[index]->next == NULL)
            {
                return false;
            }
        }

        // // Free node_ptr
        // free(node_ptr);

        // Update the dictionary size
        DICT_SIZE ++;
    }

    // Free the word variable declared before the beginning of the while loop.
    free(word);

    // Close the dictionary file
    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return DICT_SIZE;
}




// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i ++) // Traverse the entire hash table
    {
        if (table[i] != NULL) // Make sure that there is data in the bucket
        {
            // Use a loop to free the nodes in the linked list
            node *cursor = table[i];
            node *tmp = cursor;
            while(cursor->next != NULL)
            {
                cursor = cursor->next;
                free(tmp);
                tmp = cursor;
            }

            // Deal with the last cursor
            free(cursor);
        }
    }
    return true;
}