#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "linkedList_char.h"
#include <time.h>

int main(void)
{
	char ch[30];
	int n;

	printf("Enter n numbers to add to the linked list: ");
	scanf("%d", &n);

    srand(time(NULL));
	for (int r = 0; r < n; r++)
		ch[r] = char('a' + rand() % 26);

	node_t *hp;
	hp = NULL;

	hp = createList(hp, ch, n);
	printf("\n");
	displayList(hp);
	char item;

	printf("\n");
	printf("Enter a character to delete: ");
	scanf(" %c", &item);
	
	node_t *tp;

	do
	{
		tp = search(hp, item);

        if (tp->next != NULL)
			if (tp != hp)
				deleteAfter(tp);
			else
				hp = deleteBeginning(hp);

	} while (tp->next != NULL);
		
	displayList(hp);
}