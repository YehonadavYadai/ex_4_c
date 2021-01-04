#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<iostream>
using namespace std;
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

char *wordToLower(char *str, int length)
{

    for (int i = 0; 0 < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

char *getword(FILE *fp)
{
    char word[100];
    int ch;
    size_t idx;

    for (idx = 0; idx < sizeof word - 1;)
    {
        ch = fgetc(fp);
        if (ch == EOF)
            break;
        if (!isalpha(ch))
        {
            if (!idx)
                continue; // Nothing read yet; skip this character
            else
                break; // we are beyond the current word
        }
        word[idx++] = tolower(ch);
    }
    if (!idx)
        return NULL; // No characters were successfully read
    wordToLower(word, idx);
    word[idx] = '\0';
    return strdup(word);
}

//*****************************
void buildtreeInput(FILE *fp, Trie t)
{
    char str1[100];
    char newString[10][10]; 
    int i,j,ctr;
    fgets(str1, sizeof str1, stdin);	
    j=0; ctr=0;
    for(i=0;i<=(strlen(str1));i++)
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if(str1[i]==' '||str1[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            newString[ctr][j]=str1[i];
            j++;
        }
    }
    
    for(i=0;i < ctr;i++){
        inserta(t,newString[i]);
    }

}

void buildtreeFile(FILE *fp, Trie t)
{
    char *word = (char *)malloc(100 * sizeof(char));
    while (word = getWord(fp))
    {
        insert(t, word); //insert then i can free it .
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

void inserta(Trie t, char *word)
{
    node *ptr;
    int index = convert(word[0]);
    if (t.children[index] == null)
    {
        node newNode;
        t.children[index] = newNode;
        ptr=&(newNode);
    }
    else
    {
        ptr = t.children[index];
    }
    int i = 1;
    *ptr->word[0] = word[0];

    while (word[i] = !'\0'){
        *ptr->dad=TRUE;// if you here it mean you have children.
        int index = convert(word[i]);
        if (*(ptr)->children[index]==null){
            node newNodeloop;//init a new node
            strcpy(newNodeloop.word, word, i);//if its nw node we need to insert the string he represnts.
            ptr=&(newNodeloop);
        }
        else {
            ptr=*(ptr)->children[index];
        }
    }
    // we ended the word.
    *ptr->count++;
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
    ///*********************************
    void Printup(node current)
    { //i got node.
    
        if (current.dad == FALSE)
        { // if its end i guess its end of word.
            printf(" %s   %d", z, current.count);
        }
        //shold keep in the this path
        else
        {// if this end of word print and pass to his children.
            if (current.count = !0)
            {
                printf(" %s   %d", z, current.count);
            } 

            for (int i = 0; i < 26; i++)
            {
               if (current.children[i]=!NULL)
               { 
                   Printup(current.children[i]);
               }
                  
            }
        }
    }
