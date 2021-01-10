
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM_LETTERS ((int)26)
#define SIZE 1

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

void initCurrentNode(char *word, node *current)
{
    current->open = TRUE;
    current->children = (node *)malloc(sizeof(node) * NUM_LETTERS); //malloc for his suns
              //malloc for new nodee "word"
}
//this method take a word and insert into the tree.
int InsertWord(Trie *t, char *word)
{

    int len = strlen(word);
    node *ptr = t->children;
    int index = *word - 'a'; // index of char in the array
    ptr = ptr + index; 

    if (ptr->open == FALSE)
    {
        initCurrentNode(word, ptr);
    }

    //already mallocated.
    if (len==1){
         ptr->word = (char *)malloc(sizeof(char) * 11); 
            strncpy(ptr->word, word,  1);
            ptr->count++;
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
            initCurrentNode(word, ptr);
        }

        if (i == len - 1)
        {
            (ptr->count)++;
            ptr->word = (char *)malloc(sizeof(char) * len+1); 
            strncpy(ptr->word, word, i + 1);
        }
    }
return 0;
    //printf("the word in the tree :%s \n", ptr->word);
    ///printf("length of word is %d \n",len);
}

//this method get the word from the input and inserting all of the word in thr tree
void BuildTree(Trie *t)
{
    int spaces=0;
    int i = 1;
    char *pStr = (char *)malloc(sizeof(char) * 1);
    char c;

    size_t len = 0;
    char *str = malloc(sizeof(char) * 1);
    while (scanf("%c", &c) == 1)
    { // start a word

        
        //printf("your letter is : %c\n", c);
        if (c == ' ' || c == '\n'||c=='\0')
        { //if we finish the word
            
            //only of the last letter was alpha then insert.
            //if the last letter was space its not a word
            if (len>0){
            InsertWord(t, str);
            len = 0;
            free(str);
            char *str = malloc(sizeof(char) * 1);
            spaces=1;
            }
            
        }

        else

        { //keep write
        if (isalpha(c)){
            c=tolower(c);
            str[len] = c;
            len++;
            str = realloc(str, sizeof(char) * 1);}
     
        }
    }

    if(len>0){
    
    InsertWord(t, str);
    free(str);}
}



//////////////////// print
void PrintNodeS(node *node)
{ //evry node that comes in here is open.

    if (node->count > 0)
    {
        num++;
        
        printf("%s %ld\n", node->word, node->count);
    }

    if (node->dad == TRUE)
    { //if he have a sun start to check.

        for (int i = 0; i < 26; i++)
        {
            if (((node->children) + i)->open == TRUE)
            { //if there is a path

                PrintNodeS(((node->children) + i));
            }
        }
    }
}

//printf("this is the second word %s \n",t->children->children->word);
void PrintS(Trie *t)
{
   
    node *ptr = t->children;
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if ((ptr + i)->open == TRUE)
        {
            PrintNodeS(ptr + i);
        }
    }
}

void PrintNodeR(node *node)
{ //evry node that comes in here is open.

    if (node->dad == TRUE)
    { //if he have a sun start to check.

        for (int i = 25; i > -1; i--)
    {
            if (((node->children) + i)->open == TRUE)
            { //if there is a path

                PrintNodeR(((node->children) + i));
            }
        }
    }

    if (node->count > 0)
    {
        num++;
        printf("%s %ld\n", node->word, node->count);
        
    }
}

void printR(Trie *t)
{

    for (int i = 25; i > -1; i--)
    {

        if (((t->children) + i)->open == TRUE)
        {
            PrintNodeR(((t->children) + i));
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

int main(int argc, char *argcv[])
{

   printf("%s","\n");
    Trie* t = (Trie *)malloc(sizeof(Trie));
    t->children = (node *)malloc(sizeof(node) * NUM_LETTERS);
    BuildTree(t);
    if(argc==1){
     PrintS(t);}
  else if(*argcv[1]=='r'){
    printR(t);}
    FreeTrie(t);
     
   
return 0;
    }

