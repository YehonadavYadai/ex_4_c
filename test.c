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

int convert(char c)
{
    int c_value = c;
    int a_value = 'a';
    return c_value - a_value;
}

void testreadword(Trie *t, char *word)
{

    int len = strlen(word);
    node *ptr;
    int index = convert(*word);
    if ((t->children + index)->open == FALSE)
    {
        (t->children + index)->open = TRUE;
        (t->children + index)->children = (node *)malloc(sizeof(node) * NUM_LETTERS); //malloc for his suns
        (t->children + index)->word = (char *)malloc(sizeof(30));                     //malloc for new nodee "word"
        strncpy((t->children + index)->word, word, 1);

        // printf("the word in the tree\n");
        // printf("%s\n", (t->children + index)->word); //insert word

        ptr = t->children + index; //pointer to the current node.
    }
    else
    {
        ptr = t->children + index; //already mallocated.
    }

    for (int i = 1; i < len; i++)
    {
        ptr->dad = TRUE; // if you here it mean you have children.
        // printf(" ive become a dad:  %s \n", ptr->word);
        int index = convert(word[i]);

        if ((ptr->children + index)->open == FALSE)
        {
            ptr->open = TRUE;
            (ptr->children + index)->children = (node *)malloc(sizeof(node) * NUM_LETTERS); //malloc for his suns
            (ptr->children + index)->word = (char *)malloc(sizeof(30));                     //malloc for new nodee "word"
            strncpy((ptr->children + index)->word, word, i + 1);
            //printf("number leetet:%d string is:%s",i+1,ptr.)
            // printf("the word in the tree\n");
            // printf("%s\n", (ptr->children + index)->word); //insert word
            ptr = ptr->children + index;
            ptr->open = TRUE;
        }
        else
        {
            ptr = ptr->children + index;
        }
        if (i == len - 1)
        {
            int z = ptr->count;
            ptr->count = z + 1;
            // printf("word counted: %s  count :%ld \n ",ptr->word, ptr->count);
        }
    }
    // it cound how many times the word in the tree
}
// char * getline(void) {
//     char * line = malloc(100), * linep = line;
//     size_t lenmax = 100, len = lenmax;
//     int c;

//     if(line == NULL)
//         return NULL;

//     for(;;) {
//         c = fgetc(stdin);
//         if(c == EOF)
//             break;

//         if(--len == 0) {
//             len = lenmax;
//             char * linen = realloc(linep, lenmax *= 2);

//             if(linen == NULL) {
//                 free(linep);
//                 return NULL;
//             }
//             line = linen + (line - linep);
//             linep = linen;
//         }

//         if((*line++ = c) == '\n')
//             break;
//     }
//     *line = '\0';
//     return linep;
// }

void buildtreeInput(Trie *t)
{
    char str1[300];
    char newString[30][10];
    int i, j, ctr;
    while( fgets(str1, sizeof str1, stdin)) {
    //fgets(str1, sizeof str1, stdin);
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
        //printf("the word been insered is :%s \n", newString[i]);
        testreadword(t, newString[i]);
    }
    }
}
void printNode(node *node)
{ //evry node that comes in here is open.

    int z = node->count;
    if (z > 0)
    {
        num++;
        printf("%s  %d \n", node->word, z);
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

    for (int i = 0; i < 26; i++)
    {

        if (((t->children) + i)->open == TRUE)
        {
            printNode(((t->children) + i));
        }
    }
}

void printNodeR(node *node)
{ //evry node that comes in here is open.

    if (node->dad == TRUE)
    { //if he have a sun start to check.

        for (int i = 0; i < 26; i++)
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
