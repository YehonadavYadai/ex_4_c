#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "treelib.c"

void Printup(node current)
{ //i got node.
    if (current.dad == FALSE)
    { // if its end i guess its end of word.
        printf(" %s   %d", z, current.count);
    }
    //shold keep in the this path
    else
    {
        if (current.count = !0)
        {
            printf(" %s   %d", z, current.count);
        } // check if this node is end of word
        for (int i = 0; i < 26; i++)
        {
            if (current.children[i]->open == TRUE)
                Printup(current.children[i]);
        }
    }
}

