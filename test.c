#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM_LETTERS ((int)26)
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
    int i = 1;
    int len=strlen(word);
    node *ptr;
    int index = convert(*word);
    printf("%d",index);
    if ((t->children + index)->open == FALSE)
    {
       (t->children + index)->open=TRUE;
        (t->children + index)->children = (node *)malloc(sizeof(node) * NUM_LETTERS); //malloc for his suns
        (t->children + index)->word = (char *)malloc(sizeof(30));                     //malloc for new nodee "word"
        strncpy((t->children + index)->word, word, i);
        
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
        int index = convert(word[i]);

        if ((ptr->children + index)->open == FALSE)
        {
            ptr->open=TRUE;
            (ptr->children + index)->children = (node *)malloc(sizeof(node) * NUM_LETTERS); //malloc for his suns
            (ptr->children + index)->word = (char *)malloc(sizeof(30));                     //malloc for new nodee "word"
            strncpy((ptr->children + index)->word, word, i + 1);
        
            // printf("the word in the tree\n");
            // printf("%s\n", (ptr->children + index)->word); //insert word
        }
        else
        {
             ptr = ptr->children + index;
        }
        if(i==len-1){ 
            int z=ptr->count;
            printf("beore couunt: %ld ",z);
            ptr->count=z+1;
            printf("after couunt :%ld ",ptr->count);
        }
           
    }
    // it cound how many times the word in the tree
    
}



void buildtreeInput(Trie* t)
{
    char str1[300];
    char newString[30][10];
    int i, j, ctr;
    fgets(str1, sizeof str1, stdin);
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
        printf("the word been insered is :%s \n", newString[i]);
        testreadword(t, newString[i]);
    }
}


 void printup(Trie* t){
printf("i got inti print");
 for (int i = 0; i < 26; i++)
 {
     node* ptr=t->children;
     printf("%ld",ptr->count);
    
     
   if ( ptr->open==TRUE)
    {
     

//        //if this letter is open print all his words
//        printnode((t->children+index));
          ptr=ptr+1; 
           
        }
       
   
 }

}

// void printnode(node* node){//evry node that comes in here is open.
//     printf("this is the word %s",node->word);
//     //CHECK IF HE HAVE SUNS
//    if ((node->children + index)->dad == TRUE){
//        for (int i = 0; i < 26; i++)
//        {
//            if ((node->children + index)->open == TRUE){
//        //if this letter is open print all his words
//        printnode((node.children+index));
//        }
       
   
//     }
    

// }
