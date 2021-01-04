struct boolean ; 
struct node ; 
struct Trie; 


char* wordToLower(char* str,int length);
   
char*getword(FILE *fp);
   
void buildtree(FILE *fp, Trie t);

int convert(char c);

void insert(Trie t, char *word);

void Printup(node current);




