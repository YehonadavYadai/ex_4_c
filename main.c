#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "treelib.c"
#include "printlib.c"
#include "scan.c"

int main ()
{
Trie t;
FILE *fptr=fopen("input.txt","r");
buildtree(fptr,t);
// done building tree.

// now i print the tree.
for (int i = 0; i < 26; i++)
{
    Printup(t.children[i]):
}


return 0;
}




