#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
typedef struct
{
	char name[20];
	char surname[40];
	int year;
}people_t;


void swap(people_t *a, people_t *b)
{
	people_t temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(people_t *people, int size)
{
	int pass = 0, sorted;

	do
	{
		sorted = 1;
		for (int k = 0; k < size - pass - 1; k++)
			if (strcmp((people + k)->surname, (people + k + 1)->surname) > 0)
			{
				swap(people + k, people + k + 1);
				sorted = 0;
			}
			else if (strcmp((people + k)->surname, (people + k + 1)->surname) == 0)
			{
				if (strcmp((people + k)->name, (people + k + 1)->name) > 0)
				{
					swap(people + k, people + k + 1);
					sorted = 0;
				}
			}
		pass++;
	} while (!sorted);
}

int readFromFile(FILE *in, people_t *people, int count)
{
	int r = 0;
	while (fscanf(in, " %s %[^0-9] %d", (people + r)->name, (people + r)->surname, &(people + r)->year) != EOF && (r < count))
		r++;
	fclose(in);
	return(r);
}

void writeToFile(FILE *out, people_t *people, int size)
{
	for (int r = 0; r < size; r++)
		fprintf(out,"%-20s %-20s      %4d\n", (people + r)->name, (people + r)->surname, (people + r)->year);
}

int main(void)
{
	FILE *in = fopen("people.txt", "r");
	FILE *out = fopen("sorted.txt", "w");

	if (in == NULL)
		printf("Error has occured when opening the input file.\n");
	else
	{
		int count = 50;

		people_t *people;
		people = (people_t *)malloc(sizeof(people_t) * count);

		count = readFromFile(in, people, count);

		bubbleSort(people, count);

		writeToFile(out, people, count);

		printf("Completed successfully, check the file.\n");
	}
	return(0);
}
