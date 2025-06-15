#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_struct2.h"

void displayList(node_t *hp);

node_t * recReverse(node_t *hp);

void displayListRec(node_t *hp);

int main(void)
{
    FILE *in = fopen("students.bin","rb");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        node_t *hp; 
        hp = NULL;
        LType temp;

        fread(&temp, sizeof(LType), 1, in);
        hp = addBeginning(hp, temp);

        node_t *current = hp;

        while(fread(&temp, sizeof(LType), 1, in) == 1)
        {
            addAfter(current, temp);
            current = current->next;
        }

        printf("Content of the file\n");
        displayListRec(hp);

        hp = recReverse(hp);
        printf("\nReverse of the list\n");
        displayListRec(hp);
    }
    fclose(in);
    return(0);
}

void displayList(node_t *hp)
{
    node_t *tp = hp;
    while(tp != NULL)
    {
        printf("%d %0.2f -> ", tp->data.id, tp->data.cgpa);
        tp = tp->next;
    }

    printf("NULL\n"); 
}

void displayListRec(node_t *hp)
{
    if (hp != NULL) 
    {
        printf("%d %0.2f -> ", hp->data.id, hp->data.cgpa);
        displayListRec(hp->next);
    }
    else    
        printf("NULL\n\n");
}

node_t * recReverse(node_t *hp)
{
    if (hp == NULL || hp->next == NULL) // list does not exist or only has one node
        return(hp);

    node_t *rest = recReverse(hp->next); //recursive call on rest

    hp->next->next = hp;
    hp->next = NULL;

    return (rest);
}