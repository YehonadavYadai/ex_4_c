#include "mylib.c"
#define SIZE 1
int main()
{

   
    Trie* t = (Trie *)malloc(sizeof(Trie));
    t->children = (node *)malloc(sizeof(node) * NUM_LETTERS);
    testbuild(t);
    printcheck(t);
    //printR(t);
    FreeTrie(t);
     
   
return 0;
    }

