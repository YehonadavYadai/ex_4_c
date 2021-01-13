
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM_LETTERS ((int)26)
#define SIZE 2

typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean; // Quich boolean Struct

typedef struct node
{

    int dad;
    boolean open;
    char *word;
    int check[26];
    long unsigned int count;
    struct node *children[NUM_LETTERS]; // evrey node have array of nodes "children"

} node;

typedef struct Trie
{
    struct node *children[NUM_LETTERS];
    int check[26];
} Trie;

//this method take a word and insert into the tree.
int InsertWord(Trie *t, char *word)

{
    //printf(" i was inserted: %s \n", word);
    int len = strlen(word);

    int index = *word - 'a'; // index of char in the array

    // check if he need to malloc
    if (t->check[index] == 0)
    {

        //"mark" sun.
        t->check[index] = 1;
        //malloc for first sun
        t->children[index] = (node *)malloc(sizeof(node));
        if (t->children[index] == NULL)
        {
            printf("sorry you dont have enoght memory\n");
            return 0;
        }
        //another "mark"
        t->children[index]->open = TRUE;
        //set without child as start.
        t->children[index]->dad = 0;
    }
    node *ptr = t->children[index];

    for (int i = 1; i < len; i++)
    {
        char c = *(word + i);
        index = c - 'a';
        ptr->dad = 1; // if you here it mean you have children.

        if (ptr->check[index] == 0) //if sun not exit create him
        {
            //"mark" sun .
            ptr->check[index] = 1;

            //malloc sun
            ptr->children[index] = (node *)malloc(sizeof(node));
            if (ptr->children[index] == NULL)
            {
                printf("sorry you dont have enoght memory\n");
                return 0;
            }

            //another "mark" for sun
            ptr->children[index]->open = TRUE;
            //set "no dad" in init.
            ptr->children[index]->dad = 0;
        }
        //moving to the sun.
        ptr = ptr->children[index];

        if ((i == len - 1) && (isalpha(c))) //if we in the end of the Word ,copy the word.
        {
            //count the word in her node.
            ptr->count++;

            //if its first time of word we will allocte space for her
            if (ptr->count == 1)
            {
                // alloc and copy.
                ptr->word = (char *)malloc(sizeof(char) * len + SIZE);
                if (ptr->word == NULL)
                {
                    printf("sorry you dont have enoght memory\n");
                    return 0;
                }

                strncpy(ptr->word, word, i + 1);
            }
        }
    }

    return 1;
}

//this method get the word from the input and inserting all of the word in thr tree
int BuildTree(Trie *t)
{

    int i = 1;
    char c;
    size_t len = 0;

    //alocte for first char.

    char *str = malloc(sizeof(char) * 2);
    if (str == NULL)
    {
        printf("sorry you dont have enoght memory\n");
        return 0;
    }

    // no memory. safely return/throw ...
    // while there is stiil input
    while (scanf("%c", &c) == 1)
    {

        //if we finish the word
        if (c == ' ' || c == '\n' || c == '\0')
        {

            //if its real word and not bunch of "spaces"
            if (len > 0)
            {
                //insert and copy in the tree
               int succsed= InsertWord(t, str);
               if(succsed==0){
                   return succsed;
               }

                //you can free the word
                free(str);
                // aloocate to start next word.
                str = (char *)malloc(sizeof(char));
                if (str == NULL)
                {
                    printf("sorry you dont have enoght memory\n");
                    return 0;
                }

                // set lenght of word to zero
                len = 0;
            }
        }
        //middle of the word, keep write
        else
        { //keep write

            if (isalpha(c))
            {
                //alocte only if is a char.
                str = (char *)realloc(str, sizeof(char) * len + 1);
                if (str == NULL)
                {
                    printf("sorry you dont have enoght memory\n");
                    return 0;
                }

                // make the char lower
                c = tolower(c);
                //put it in the word.
                str[len] = c;
                len++;
            }
        }
    }

    if (len > 0)
    {

        InsertWord(t, str);
        printf("word inserted is : %s \n", str);
        free(str);
    }

    free(str);
    return 1;
}

//////////////////// print
void PrintNodeS(node *node)
{ //evry node that comes in here is open.
    int was = 0;
    if (node->count > 0)
    {

        printf("%s %ld\n", node->word, node->count);
        was = 1;
        free(node->word);
    }

    if (node->dad == 1)
    {
        // { //if he have a sun start to check.

        for (int i = 0; i < 26; i++)
        {
            if (was)
            {
            }

            if (node->check[i] == 1)
            { //if there is a path

                PrintNodeS(node->children[i]);
            }
        }
    }
    free(node);
}

//printf("this is the second word %s \n",t->children->children->word);
void PrintS(Trie *t)
{

    for (int i = 0; i < NUM_LETTERS; i++)
    {

        if (t->check[i] == 1)
        {

            PrintNodeS(t->children[i]);
        }
    }
    free(t);
}

void PrintNodeR(node *node)
{ //evry node that comes in here is open.
    if (node->dad == 1)
    {
        for (int i = 25; i > -1; i--)
        {

            if (node->check[i] == 1)
            { //if there is a path

                PrintNodeR(node->children[i]);
            }
        }
    }

    if (node->count > 0)
    {

        printf("%s %ld\n", node->word, node->count);

        free(node->word);
    }
    free(node);
}

//printf("this is the second word %s \n",t->children->children->word);
void PrintR(Trie *t)
{

    for (int i = 25; i > -1; i--)
    {

        if (t->check[i] == 1)
        {

            PrintNodeR(t->children[i]);
        }
    }
    free(t);
}

int main(int argc, char *argcv[])
{

    //printf("%s", "\n");
    Trie *t = (Trie *)malloc(sizeof(Trie));
     if (t == NULL)
        {
            printf("sorry you dont have enoght memory\n");
            return 0;
        }
    int succseed=BuildTree(t);
    if(succseed){
    if (argc == 1)
    {
        PrintS(t);
    }
    else if (*argcv[1] == 'r')
    {
        PrintR(t);
    }
    }
    return 0;
}
