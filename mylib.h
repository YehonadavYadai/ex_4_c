typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean; // Quich boolean Struct

typedef struct node
{
    boolean open = FALSE;
    boolean dad = FALSE;
    char *word;
    long unsigned int count;
    struct node *children[26]; // evrey node have array of nodes "children"
} node;

typedef struct Trie
{
    struct node* children[26];
} Trie;


char* wordToLower(char* str,int length);
   
char*getword(FILE *fp);
   
void buildtree(FILE *fp, Trie t);

int convert(char c);

void insert(Trie t, char *word);

void Printup(node* current);




