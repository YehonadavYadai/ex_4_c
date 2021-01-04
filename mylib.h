#define NUM_LETTERS ((int)26)
typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean;// Quich boolean Struct

typedef struct node
{
    boolean open;
    boolean dad ;
    char *word;
    long unsigned int count;
    struct node* children[NUM_LETTERS]; // evrey node have pointers to the children
} node;

typedef struct Trie
{
    node* children[NUM_LETTERS];

} Trie;


char* wordToLower(char* str,int length);
   
char*getword(FILE *fp);
   
void buildtreeFile(FILE *fp, Trie t);

void buildtreeInput(FILE *fp, Trie t);

int convert(char c);

void insert(Trie t, char *word);

void Printup(node* current);
void inserta(Trie t, char *word):
void buildtreeInput(FILE *fp, Trie t);





