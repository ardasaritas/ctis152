#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

int readFromFile(FILE *in, char names[][MAX]);

void display(char names[][MAX], int size); 

int binarySearch(char names[][MAX], int start, int finish, char key[]);

int main(void)
{
	FILE *in = fopen("companies.txt", "r");

	if (in == NULL)
		printf("Error has occurred when opening the input file.\n");
	else
	{
		char names[MAX][MAX], key[MAX];
		int index, actsize = readFromFile(in, names);

		display(names, actsize);

		do
		{
			printf("Enter a company name to search (or end to stop searching): ");
			scanf(" %[^\n]", key);

			if (strcmp(key, "end") == 0)
				return(0);

			index = binarySearch(names, 0, actsize - 1, key);

			if (index == -1)
				printf("%s could not be found\n\n", key);
			else
				printf("%s is found at index %d\n\n", key, index);

		} while (strcmp(key, "end") != 0);
	}
	return(0);
}

int readFromFile(FILE *in, char names[][MAX])
{
	int count = 0; 
	while (fscanf(in, " %[^\n]", names[count]) != EOF && (count < MAX))
		count++;
	return(count);
}

void display(char names[][MAX], int size)
{
	printf("The List of Companies\n");
	printf("---------------------\n\n");
	for (int r = 0; r < size; r++)
		printf("%s\n", names[r]);
}

int binarySearch(char names[][MAX], int start, int finish, char key[])
{
	int mid;

	while (start <= finish)
	{
		mid = (start + finish) / 2;

		if (strcmp(names[mid], key) == 0)
			return(mid);
		else if (strcmp(names[mid], key) < 0)
			finish = mid - 1;
		else
			start = mid + 1;
	}
	return(-1);
}
