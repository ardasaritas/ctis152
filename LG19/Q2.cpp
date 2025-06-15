#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_struct.h"

node_t *createList(FILE *in, node_t *hp);

node_t *deletePolicy(node_t *hp);

int main(void)
{
    FILE *in = fopen("policies.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        node_t *hp;
        hp = NULL;
        hp = createList(in, hp);

        node_t *tp;
        tp = hp;
        
        printf("\nInitial List is: ");
        while (tp != NULL)
        {
            printf("[%d %s %d] -> ", tp->data.ID, tp->data.surname, tp->data.entranceYear);
            tp = tp->next;
        }
        printf("NULL\n\n");

        hp = deletePolicy(hp);
        tp = hp;

        printf("*** Policies before year 2023 will be deleted ***\n\n");
        while (tp != NULL)
        {
            printf("[%d %s %d] -> ", tp->data.ID, tp->data.surname, tp->data.entranceYear);
            tp = tp->next;
        }
        printf("NULL\n");
    }
    fclose(in);
    return (0);
}

node_t *createList(FILE *in, node_t *hp)
{
    LType temp; 
    fscanf(in, "%d %s %d", &temp.ID, temp.surname, &temp.entranceYear);
    hp = addBeginning(hp, temp);
    node_t *tp = hp;

    while (fscanf(in, "%d %s %d", &temp.ID, temp.surname, &temp.entranceYear) != EOF)
    {
        addAfter(tp, temp);
        tp = tp->next;
    }
    return(hp);
}

node_t *search(node_t *hp)
{
    if (hp->data.entranceYear >= 2023)
        while (hp->next != NULL && hp->next->data.entranceYear >= 2023)
            hp = hp->next;
    return(hp);
}

node_t *deletePolicy(node_t *hp)
{
    node_t *tp;

    tp = search(hp);
    while (tp->next != NULL)
    {
        if (tp == hp)
            hp = deleteBeginning(hp);
        else    
            deleteAfter(tp);
        tp = search(hp);
    }
    return(hp);
}