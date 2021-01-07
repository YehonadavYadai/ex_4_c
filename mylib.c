#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM_LETTERS ((int)26)

int num = 0;
typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean; // Quich boolean Struct

typedef struct node
{

    boolean dad;
    boolean open;
    char *word;
    long unsigned int count;
    struct node *children; // evrey node have array of nodes "children"

} node;

typedef struct Trie
{
    struct node *children;
} Trie;

void init(char *word, node *current)
{
    current->open = TRUE;
    current->children = (node *)malloc(sizeof(node) * NUM_LETTERS); //malloc for his suns
              //malloc for new nodee "word"
}
int insertWord(Trie *t, char *word)
{

    int len = strlen(word);
    node *ptr = t->children;
    int index = *word - 'a'; // index of char in the array
    if ((ptr + index)->open == FALSE)
    {
        init(word, ptr + index);
    }
    ptr = ptr + index; //already mallocated.
    if (len==1){
         ptr->word = (char *)malloc(sizeof(char) * 11); 
            strncpy(ptr->word, word,  1);
    return 0;
    }
    for (int i = 1; i < len + 1; i++)
    {
        char c = *(word + i);
        index = c - 'a';
        ptr->dad = TRUE; // if you here it mean you have children.
        ptr = (ptr->children) + index;
        if (ptr->open == FALSE)
        {
            init(word, ptr);
        }

        if (i == len - 1)
        {
            (ptr->count)++;
            ptr->word = (char *)malloc(sizeof(char) * i+1); 
            strncpy(ptr->word, word, i + 1);
        }
    }
return 0;
    //printf("the word in the tree :%s \n", ptr->word);
    ///printf("length of word is %d \n",len);
}


void testbuild(Trie *t)
{
    int spaces=0;
    int i = 1;
    char *pStr = (char *)malloc(sizeof(char) * 1);
    char c;
 printf(" %s", "");
    size_t len = 0;
    char *str = malloc(sizeof(char) * 1);
    while (scanf("%c", &c) == 1)
    { // start a word

        
        //printf("your letter is : %c\n", c);

        if (c == ' ' || c == '\n'||c=='\0')
        { //if we finish the word
            
            // if the last leeter was "no space"
            insertWord(t, str);
            len = 0;
            free(str);
            char *str = malloc(sizeof(char) * 1);
            spaces=1;
        }
        else

        { //keep write
        if (isalpha(c)){
            str[len] = c;
            len++;
            str = realloc(str, sizeof(char) * 1);}
     
        }
    }

    
    insertWord(t, str);
    free(str);
}



//////////////////// print
void printNode(node *node)
{ //evry node that comes in here is open.

    if (node->count > 0)
    {
        num++;
        printf(" %s", "");
        printf(" %s  %ld  \n ", node->word, node->count);
    }

    if (node->dad == TRUE)
    { //if he have a sun start to check.

        for (int i = 0; i < 26; i++)
        {
            if (((node->children) + i)->open == TRUE)
            { //if there is a path

                printNode(((node->children) + i));
            }
        }
    }
}

//printf("this is the second word %s \n",t->children->children->word);
void printcheck(Trie *t)
{
   
    node *ptr = t->children;
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if ((ptr + i)->open == TRUE)
        {
            printNode(ptr + i);
        }
    }
}

void printNodeR(node *node)
{ //evry node that comes in here is open.

    if (node->dad == TRUE)
    { //if he have a sun start to check.

        for (int i = 25; i > -1; i--)
    {
            if (((node->children) + i)->open == TRUE)
            { //if there is a path

                printNodeR(((node->children) + i));
            }
        }
    }
    int z = node->count;
    if (z > 0)
    {
        num++;
        printf(" %s  %d \n ", node->word, z);
    }
}

void printR(Trie *t)
{

    for (int i = 25; i > -1; i--)
    {

        if (((t->children) + i)->open == TRUE)
        {
            printNodeR(((t->children) + i));
        }
    }
}

/////////////////FREE FREE FREE///////////////
void FreeNode(node *node)
{ //evry node that comes in here is open.

    if (node->dad == TRUE)
    { //if he have a sun start to check.

        for (int i = 0; i < 26; i++)
        {
            if (((node->children) + i)->open == TRUE)
            { //if there is a path

                FreeNode(((node->children) + i));
            }
        }
    }
    //printf("node : %s is free\n",node->word);
    free(node->word);
    free(node->children);
}

//printf("this is the second word %s \n",t->children->children->word);
void FreeTrie(Trie *t)
{
    node *ptr = t->children;
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if ((ptr + i)->open == TRUE)
        {
            FreeNode(ptr + i);
        }
    }
    free(t->children);
    free(t);
}
