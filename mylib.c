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

 void init(char* word, node* current, int size)
 {
     current->open = TRUE;
     current->children = (node*)malloc(sizeof(node) * NUM_LETTERS); //malloc for his suns
     current->word = (char *)malloc(sizeof(char)*20);                     //malloc for new nodee "word"
     strncpy(current->word, word, size+1);
     // printf("the word in the tree :%s \n", current->word);

    
 }
void insertWord(Trie *t, char *word)
{
    
    int len = strlen(word);
    node *ptr=t->children;
    int index = *word - 'a'; // index of char in the array
    if ((ptr+index)->open == FALSE)
    {
        init(word,ptr + index,0);
    }  
    ptr = ptr + index; //already mallocated.
    

    for (int i = 1; i < len+1; i++)
    {
        char c=*(word+i);
        index=c-'a';
        ptr->dad = TRUE; // if you here it mean you have children.
        ptr=(ptr->children) + index;
        if (ptr->open == FALSE)
        {
            init(word,ptr,i);
        } 

        if (i==len-1) {
            (ptr->count)++;
        } 
    }
    
    //printf("the word in the tree :%s \n", ptr->word);
    ///printf("length of word is %d \n",len);
    
}

void buildtreeInput(Trie *t)
{
    char *str1 = (char *)malloc(sizeof(char) * 300);
    char newString[30][20];
    int i, j, ctr;
    while (fgets(str1, 300, stdin))
    {
        j = 0;
        ctr = 0;
        for (i = 0; i <= (strlen(str1)); i++)
        {
            // if space or NULL found, assign NULL into newString[ctr]
            if (str1[i] == ' ' || str1[i] == '\0')
            {
                newString[ctr][j] = '\0';
                ctr++; //for next word
                j = 0; //for next word, init index to 0
            }
            else
            {
                if (isalpha(str1[i]))
                {

                    newString[ctr][j] = tolower(str1[i]);
                    j++;
                }
            }
        }

        for (i = 0; i < ctr; i++)
        {
            printf("the word been insert to the tree is :%s \n", newString[i]);
            insertWord(t, newString[i]);
        }
    }
    free(str1);
}

//////////////////// print
void printNode(node *node)
{ //evry node that comes in here is open.

    
    //printf("%s  %d \n", node->word, z);
    if (node->count > 0)
    {
        num++;
        printf("%s  %ld \n", node->word, node->count);
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
node* ptr=t->children;
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if ((ptr+i)->open == TRUE)
        {
            printNode(ptr+i);
        }
    }
}






void printNodeR(node *node)
{ //evry node that comes in here is open.

    if (node->dad == TRUE)
    { //if he have a sun start to check.

        for (int i = 0; i < NUM_LETTERS; i++)
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
        printf("%s  %d \n", node->word, z);
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
node* ptr=t->children;
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if ((ptr+i)->open == TRUE)
        {
            FreeNode(ptr+i);
        }
    }
    free(t->children);
    free(t);
}

