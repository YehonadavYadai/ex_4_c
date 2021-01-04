#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* wordToLower(char* str,int length)
    {

    for(int i = 0; 0<; i++)
        {
        str[i] = tolower(str[i]);
        } 

    }

char*getword(FILE *fp)
    {
    char word[100];
    int ch; 
    size_t idx ;

    for (idx=0; idx < sizeof word -1; )
        { 
        ch = fgetc(fp);
        if (ch == EOF) break;
        if (!isalpha(ch)) 
            {
           if (!idx) continue; // Nothing read yet; skip this character
           else break; // we are beyond the current word
            }
        word[idx++] = tolower(ch);
        }
    if (!idx) return NULL; // No characters were successfully read
    wordToLower(word,idx);
    word[idx] = '\0';
    return strdup(word);
}

