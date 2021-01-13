
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM_LETTERS ((int)26)
#define SIZE 2
int inputfree = 0;
int wordmalloc = 0;
int numMalloc = 0;
int freenum = 0;
int num = 0;
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

// void initCurrentNode(char *word, node *current)
// {
//     current=(node*)malloc(sizeof(node));// give e a space of 1 node.
//     current->open = TRUE;
//     //current->children = (node *)malloc(sizeof(node) * NUM_LETTERS); //malloc for his suns
//               //malloc for new nodee "word"
// }
//this method take a word and insert into the tree.
int InsertWord(Trie *t, char *word)
{

    int len = strlen(word);
    //node *ptr = t->children;//its get the right pointer
    int index = *word - 'a'; // index of char in the array
    //ptr = ptr + index;

    // check if he need to malloc
    if (t->check[index] == 0)
    {
        printf("im here once");

        t->check[index] = 1;
        //initCurrentNode(word, t->children[index]);
        t->children[index] = (node *)malloc(sizeof(node));
        //numMalloc++;
        t->children[index]->open = TRUE;
        t->children[index]->dad = 0;
       
    }
    node *ptr = t->children[index];

    for (int i = 1; i < len; i++)
    {
        char c = *(word + i);
        index = c - 'a';
        ptr->dad = 1; // if you here it mean you have children.
        //ptr = (ptr->children) + index;

        if (ptr->check[index] == 0) //if sun not exit create him
        {

            ptr->check[index] = 1;

            //initCurrentNode(word, ptr);
            ptr->children[index] = (node *)malloc(sizeof(node));
            //numMalloc++;
            ptr->children[index]->open = TRUE;
            ptr->children[index]->dad = 0;
           
        }

        ptr = ptr->children[index]; //moving to the sun.

        if ((i == len - 1) && (isalpha(c))) //if we in the end of the Word ,copy the word.
        {

            ptr->count++;

            if (ptr->count == 1)
            {

                ptr->word = (char *)malloc(sizeof(char) * len + SIZE);
                //numMalloc++;
                strncpy(ptr->word, word, i + 1);
            }
            
        }
    }

    return 0;
}

//this method get the word from the input and inserting all of the word in thr tree
void BuildTree(Trie *t)
{
    char* str2;
    int spaces = 0;
    int i = 1;
    char c;
    size_t len = 0;
    char *str = malloc(sizeof(char) * 2);
    numMalloc++;
    while (scanf("%c", &c) == 1)
    { // start a word

        //printf("your letter is : %c\n", c);
        if (c == ' ' || c == '\n' || c == '\0')
        { //if we finish the word
            //only of the last letter was alpha then insert.
            //if the last letter was space its not a word
            if (len > 0)
            {
                InsertWord(t, str);
                //printf("word inserted is : %s \n", str);
                free(str);
                str=(char*)malloc(sizeof(char));
                inputfree++;
                len = 0;
                numMalloc++;
                spaces = 1;
            }
        }

        else
        { //keep write
            if (isalpha(c))
            {
                str=(char *)realloc(str, sizeof(char)*len+1);

                //str = realloc(str, sizeof(char) * (len + 1));
                c = tolower(c);
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
        inputfree++;
    }
    free(str);
}

//////////////////// print
void PrintNodeS(node *node)
{ //evry node that comes in here is open.
int was=0;
    if (node->count > 0)
    {

        printf("%s %ld\n", node->word, node->count);
        was=1;
        free(node->word);
        freenum++;
    }

    if (node->dad == 1)
    {
        // { //if he have a sun start to check.

        for (int i = 0; i < 26; i++)
        {
            if (was){
        
            }

            if (node->check[i] == 1)
            { //if there is a path

                PrintNodeS(node->children[i]);
            }
        }
    }
    free(node);
    freenum++;
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
    freenum++;
}

// void PrintNodeR(node *node)
// { //evry node that comes in here is open.

//     if (node->dad == TRUE)
//     { //if he have a sun start to check.

//         for (int i = 25; i > -1; i--)
//     {
//             if (((node->children) + i)->open == TRUE)
//             { //if there is a path

//                 PrintNodeR(((node->children) + i));
//             }
//         }
//     }

//     if (node->count > 0)
//     {
//         num++;
//         printf("%s %ld\n", node->word, node->count);

//     }
// }

// void printR(Trie *t)
// {

//     for (int i = 25; i > -1; i--)
//     {

//         if (((t->children) + i)->open == TRUE)
//         {
//             PrintNodeR(((t->children) + i));
//         }
//     }
// }

/////////////////FREE FREE FREE///////////////
void FreeNode(node *node)
{ //evry node that comes in here is open.

    if (node->dad == TRUE)
    { //if he have a children go free them!

        for (int i = 0; i < 26; i++)
        {
            if (node->check[i] == 1)
            { //if there is a path

                FreeNode(node->children[i]);
            }
        }
    }
    //printf("node : %s is free\n",node->word);
    free(node->word);
    free(node->children);
    free(node);
}

//printf("this is the second word %s \n",t->children->children->word);
void FreeTrie(Trie *t)
{

    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (t->check[i] == 1)
        {
            FreeNode(t->children[i]);
        }
    }

    free(t);
}

int main(int argc, char *argcv[])
{

    printf("%s", "\n");
    Trie *t = (Trie *)malloc(sizeof(Trie));
    BuildTree(t);
    //     if(argc==1){
    //      PrintS(t);}
    //   else if(*argcv[1]=='r'){
    //printR(t);}
    //   }
    //FreeTrie(t);
    PrintS(t);
    printf("num of malloc is : %d \n", numMalloc);
    printf("num of free is %d \n", inputfree);

    return 0;
}
