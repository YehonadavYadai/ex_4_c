#include "mylib.c"

int main()
{
     
    Trie* t = (Trie *)malloc(sizeof(Trie));
    t->children = (node *)malloc(sizeof(node) * NUM_LETTERS);
    buildtreeInput(t);
    printcheck(t);
    //printR(t);
     FreeTrie(t);
    return 0 ;
}