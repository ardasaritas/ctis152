#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_str.h"

int main(void)
{
	node_t *headp;
	headp = NULL;
	
	node_t *longest;

	char strings[15][15];
	int r = 0;
	do
	{
		printf("Enter a string: ");
		scanf(" %s", strings[r]);
	} while (strcmp(strings[r++], "end"));

	headp = createList(headp, strings, r - 1);
	printf("\n");
	displayList(headp);
	
	char inserted[15];
	printf("\nEnter a name to insert after the longest name: ");
	scanf(" %s", inserted);

	longest = findLongest(headp);
	printf("\nThe longest name in the list: %s\n", longest->data);

	addAfter(longest, inserted);
	
	printf("\n");
	displayList(headp);
	return(0);
}
