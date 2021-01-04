#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_LETTERS ((int)26)

typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean; // Quich boolean Struct

typedef struct node
{
    boolean open = FALSE;
    boolean dad = FALSE;
    char *word;
    long unsigned int count;
    struct node *children[NUM_LETTERS]; // evrey node have array of nodes "children"
} node;

typedef struct Trie
{
    struct node *children[NUM_LETTERS];
} Trie;

void buildtree(FILE *fp, Trie t)
{
    char *word=(char*) malloc(100*sizeof(char));
    while (word = getWord(fp))
    {
        insert(t, word);//insert then i can free it .
        free(word);
    }
    //rewind(fp1);
    fclose(fp);
}

int convert(char c)
{
    int c_value = c;
    int a_value = 'a';
    return c_value - a_value;
}

void insert(Trie t, char *word)
{
    int index = convert(word[0]);
    node currentnode = t.children[index];
    currentnode.open = TRUE;
    int i = 1;
    currentnode.word[0] = word[0];
    while (word[i] = !'\0')
    {                           //until end of word
        currentnode.dad = TRUE; // the node we came from is become "dad"
        index = convert(word[i]);
        currentnode = currentnode.children[index]; // move to the sun
        currentnode.open = TRUE;                   //flag its a way in the
                                                   // 1. put the word+char in the node
        strcpy(currentnode.word, word, i);         // copy the string from his dad to the sun rom 0 to i-2.
        i++;
    }
    //end of word
    currentnode.count++;
}
