#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_str.h"

node_t *createList(FILE *in, node_t *hp);

node_t *search(node_t *hp, char *item);

node_t *removeWord(node_t *hp, char *word);

int main(void)
{
    FILE *in = fopen("words.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        node_t *hp = NULL;
        printf("\n");
        hp = createList(in, hp);

        char delString[10];
        printf("\nEnter a string to delete: ");
        scanf(" %s", delString);
        
        hp = removeWord(hp, delString);

        while (hp != NULL)
        {
            printf("%s -> ", hp->data); 
            hp = hp->next;
        }

        printf("NULL\n\n");
    }
    fclose(in);
    return(0);
}

node_t *search(node_t *hp, char *item)
{
    while (hp->next != NULL && strcmp(item, hp->next->data) > 0)
        hp = hp->next; 
    return(hp);
}

node_t *createList(FILE *in, node_t *hp)
{
    LType temp[20]; 
    fscanf(in," %s", temp);
    hp = addBeginning(hp, temp);

    while (fscanf(in," %s", temp) != EOF)
    {
        node_t *tp = search(hp, temp);
        
        if (hp == tp && strcmp(temp, hp->data) < 0)
            hp = addBeginning(hp, temp);
        else    
            addAfter(tp, temp);
        
        displayList(hp);
    }
    return(hp);
}

node_t *removeWord(node_t *hp, char *word)
{
    while (hp != NULL && strstr(hp->data, word) != NULL) // delete nodes containing word
        hp = deleteBeginning(hp);

    node_t *current = hp;
    while (current->next != NULL)
    {
        if (strstr(current->next->data, word) != NULL) // if substring
            deleteAfter(current);
        else
            current = current->next;
    }
    return hp;
}
