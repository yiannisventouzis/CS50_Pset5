// Implements a dictionary's functionality
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

//max hashtable size 2^16
#define HASHTABLE_SIZE 65536

//struct for linked list
 typedef struct wordnode
    {
        char word[LENGTH + 1];
        struct wordnode *next;
        // struct wordnode *next;
    }

    node;
    // node* new_node = malloc(sizeof(node));

    node* hashtable[HASHTABLE_SIZE] = {NULL};

node* head = NULL;
node* cursor;
//declare word counter var
    unsigned int counter = 0;

//hash function
//https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
    inline int hashValue(const char* word)
    {
    unsigned int hash = 0;
    for (int i=0, n=strlen(word); i<n; i++) {
        hash = (hash << 2) ^ word[i];
    }
    return hash % HASHTABLE_SIZE;
    }

//While working on your load function, you might want to also implement your size function –
//it just returns the number of words in your dictionary. Consider a global variable for that one, too.
//That would allow you to use the same variable for both counting the words as you load them
//and returning the number of words loaded when size is called.

// Returns true if word is in dictionary else
//from doug video bool find(sllnode* head, VALUE  val);
//(pointer to first element of linked list - global var,
//data type that is inside node - what are you looking for 'word'?

bool check(const char* word)
// bool check(const char *word)
{
int index;
    cursor = head;
    while (cursor != NULL)
    {
        //compare strings on every node

        //find bucket word is in


    for(int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }
if (strcasecmp(cursor, word) == 0)
//compare w strcasecmp
        cursor = cursor->next;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char* dictionary)

{
    // TODO
//open dictionary file
    FILE *inptr = fopen(dictionary, "r");

//declare temp array for word
    char word[LENGTH + 1];
    int index;

    for(int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }
    // node* head = NULL;
    //read each word in dictionary till end of file
    while (fscanf(inptr, "%s", word) !=EOF)
        {
            //create a node and allocate memory for each word
            node *new_node = malloc(sizeof(node));
            //copy each word into node
            if (new_node == NULL)
            {
                unload();
                //speller quits
                return false;
            }
            else
            {
                strcpy(new_node->word, word);
                //new_node->word has word to hash
                index =  hashValue(word);
                //new_node should point to whatever was previous in list
                new_node->next = hashtable[index];
                hashtable[index] = new_node;

                // new_node->next = NULL;

                //increment counter for each word
                counter++;

            //run hash function
            // if (hashValue(word)) == NULL)
}

        //if index is empty add word

    //     {
    // printf("yay");
    //     }

    //     else
    //     {
    // //if index is not empty add word to that index
    // printf("no");
    //     }
            }



return 0;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // I think...
    // count function(),
    // read word;
    // counter++;
    return counter;

    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO need for loop
    // node *cursor = head;

    // while (cursor != NULL)
    // {
    //     node *temp = cursor;
    //     cursor = cursor->next;
    //     free(temp);
    // }
    return false;
}
