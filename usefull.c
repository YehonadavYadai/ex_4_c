void buildtreeInput(Trie *t)
{
    char *str1 = (char *)malloc(sizeof(char) * 300);
    char newString[30][20];
    int i, j, ctr;
    while (fgets(str1, 300, stdin))
    {
        j = 0;
        ctr = 0;
        for (i = 0; i <= (strlen(str1)); i++)
        {
            // if space or NULL found, assign NULL into newString[ctr]
            if (str1[i] == ' ' || str1[i] == '\0')
            {
                newString[ctr][j] = '\0';
                ctr++; //for next word
                j = 0; //for next word, init index to 0
            }
            else
            {
                if (isalpha(str1[i]))
                {

                    newString[ctr][j] = tolower(str1[i]);
                    j++;
                }
            }
        }

        for (i = 0; i < ctr; i++)
        {
            printf("the word been insert to the tree is :%s \n", newString[i]);
            insertWord(t, newString[i]);
        }
    }
    free(str1);
}