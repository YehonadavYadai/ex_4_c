#include "test.c"

int main()
{
     
    Trie* t = (Trie *)malloc(sizeof(Trie));
    t->children = (node *)malloc(sizeof(node) * NUM_LETTERS);
    buildtreeInput(t);
    //printup(t);
     printcheck(t);
    return 0 ;
}