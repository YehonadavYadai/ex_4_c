#include "mylib.c"
#define SIZE 1
int main(int argc, char *argcv[])
{

   
    Trie* t = (Trie *)malloc(sizeof(Trie));
    t->children = (node *)malloc(sizeof(node) * NUM_LETTERS);
    BuildTree(t);
    if(argc==1){
     PrintS(t);}
  else if(*argcv[1]=='r'){
    printR(t);}

    FreeTrie(t);
     
   
return 0;
    }

