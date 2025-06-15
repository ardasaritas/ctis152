#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedList_int.h"

node_t *searchToInsert(node_t *hp, int item);

node_t *createList(FILE *in, node_t *hp);

int main(void)
{
    FILE *in = fopen("numList.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        node_t *hp = NULL;
        hp = createList(in, hp);
        printf("\nThe list is: "); 
        displayList(hp);
    }
    fclose(in);
    return (0);
}

node_t *search(node_t *hp, int item)
{
    while (hp != NULL && hp->data != item)
        hp = hp->next;
    return(hp);
}

node_t *searchToInsert(node_t *hp, int item)
{
    if (item < hp->data)
        return(hp);
    node_t *ap = hp;
    while (ap->next != NULL)
    {
        if (item < ap->next->data)
            return ap;
        ap = ap->next;
    }
    return ap;
}

node_t *createList(FILE *in, node_t *hp)
{
    int temp;
    fscanf(in, "%d", &temp);
    hp = addBeginning(hp, temp);

    node_t *tp;
    while (fscanf(in, "%d", &temp) != EOF)
    {
        tp = searchToInsert(hp, temp);
        if (!search(hp, temp))
            if (tp == hp && temp < hp->data)
                hp = addBeginning(hp, temp);
            else  
                addAfter(tp, temp);
    }
    return(hp);
}