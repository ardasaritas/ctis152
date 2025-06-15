#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_char.h"

void menu();

void display(queue_t q); 

int main(void)
{
	queue_t q;
	initializeQ(&q);
	
	menu();
	printf("Enter the characters to be inserted to the queue (press enter to stop):\n");
	
	char item;
	scanf(" %c", &item);

	while (item != '\n')
	{
		if (item != '*' && item != '+' && item != ':' && item != '!')
			insert(&q, item);
		
		switch (item)
		{
		case '*':
			printf("The character <%c> is removed from the queue\n", remove(&q));
			break;
		case '+':
			while (!isEmptyQ(&q))
				remove(&q);
			printf("All the characters are removed from the queue\n");
			break;
		case ':':
		case '!':
			display(q);
			break;
		}
		scanf("%c", &item);
	}

	display(q);
	return 0;
}

void display(queue_t q)
{
	printf("\nThe content of the queue is: ");
	while (!isEmptyQ(&q))
		printf("%c ", remove(&q));
	printf("\n");
}

void menu()
{
	printf("*      Erase the first character (remove it from the queue)\n");
	printf("+      Kill the entire line (Empty the queue)\n");
	printf(": or ! Display the queue content\n");
	printf("Enter  Terminate the string entry and display the queue content\n\n");
}
