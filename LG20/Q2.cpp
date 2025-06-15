#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_struct2.h"

#define MAX 3

void *createList(FILE *in, node_t *hp[]);

void displayList(node_t *hp);

int main(void)
{
    FILE *in = fopen("courses.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        node_t * A[MAX] = {NULL, NULL, NULL}; 

        createList(in, A);

        for (int i = 0; i < MAX; i++)
		{
			switch (i) {
			case 0:
				printf("Aerobics\n");
				break;
			case 1:
				printf("Zumba\n");
				break;
			case 2:
				printf("Pilates\n");
				break;
			default:
				break;
			}
			printf("****************************************\n");
			displayList(A[i]);
		}
    }
    fclose(in);
    return(0);
}

void *createList(FILE *in, node_t *hp[])
{
    LType temp;
    while(fscanf(in, "%d %[^:]: %[^\r]", &temp.ID, temp.name, temp.duration) != EOF)
        hp[temp.ID - 1] = addBeginning(hp[temp.ID - 1], temp);
}

void displayList(node_t *hp)
{
    while (hp != NULL)
    {
        printf("   %d  %-21s%-8s   ->\n", hp->data.ID, hp->data.name, hp->data.duration);
        hp = hp->next;
    }
    printf("NULL\n\n");
}