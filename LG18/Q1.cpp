#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "linkedList_int.h"

int main(void)
{
	int num[20];

	node_t *headp; 
	headp = NULL;

	int r = 0;
	do
	{
		printf("Enter a number: ");
		scanf("%d", &num[r]);
	} while (num[r++] > 0);

	headp = createList(headp, num, r - 1);
	displayList(headp);
    return(0);
}