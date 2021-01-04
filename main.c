#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "mylib.h"

int main ()
{
Trie t;
FILE *fptr=fopen("input.txt","r");
buildtreeInput(fptr,t);
// done building tree.

// now i print the tree.
for (int i = 0; i < 26; i++)
{
    if (t.children[i]=!NULL){// if there a child.
    Printup(t.children[i]);
    }
}


return 0;
}




