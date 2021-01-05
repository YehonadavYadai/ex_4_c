#include "test.c"





int main()
{
     
    Trie* t = (Trie *)malloc(sizeof(Trie));
    t->children = (node *)malloc(sizeof(node) * NUM_LETTERS);
    buildtreeInput(t);
    printup(t);
     
    //  char* str = (char *)malloc(sizeof(char)*30);
    // *(str+0) = 'a'; 
    // *(str+1) = 'e';  
    // *(str+2) = 'n';  

    // testreadword(t,str);

    //inserta(*t,str);
    return 0 ;
}