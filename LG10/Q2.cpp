#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 50;

void swap(char *a, char *b)
{
	char temp[MAX]; 
	strcpy(temp, a); 
	strcpy(a, b);
	strcpy(b, temp);
}

void bubbleSort(char pc[][MAX], int size)
{
	int pass = 0, sorted;

	do
	{
		sorted = 1;
		for (int k = 0; k < size - pass - 1; k++)
			if (strcmp(pc[k], pc[k + 1]) < 0)
			{
				swap(pc[k], pc[k + 1]);
				sorted = 0;
			}
		pass++;
	} while (!sorted);
}

int main(void)
{
	
	char pc[MAX][MAX];

	int k = 0;
	do
	{
		printf("Enter a movie: "); 
		scanf(" %[^\n]", pc[k]);
	} while (strcmp(pc[k++], "end"));
	
	bubbleSort(pc, k - 1); 

	printf("Movie List:\n");
	printf("------------------------------------\n");

	for (int r = 0; r < k - 1; r++)
		printf("%d) %s\n", r + 1, pc[r]); 
	return(0);
}
