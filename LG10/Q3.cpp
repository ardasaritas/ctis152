#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char month[20];
	char name[40];
	int part;
}seminar_t;

void swap(seminar_t *a, int k)
{
	char temp[2][40];
	strcpy(temp[0], (a + k)->month);
	strcpy(temp[1], (a + k)->name);

	int itemp = (a + k)->part;

	strcpy((a + k)->month, (a + k + 1)->month);
	strcpy((a + k)->name, (a + k + 1)->name);
	(a + k)->part = (a + k + 1)->part;

	strcpy((a + k + 1)->month, temp[0]); 
	strcpy((a + k + 1)->name, temp[1]);
	(a + k + 1)->part = itemp;

}


void bubbleSort(seminar_t *seminars, int size)
{
	int pass = 0, sorted;

	do
	{
		sorted = 1;
		for (int k = 0; k < size - pass - 1; k++)
			if ((seminars + k)->part < (seminars + k + 1)->part)
			{
				swap(seminars, k);
				sorted = 0;
			}
		pass++;
	} while (!sorted);
}

void readFromFile(FILE *in, seminar_t *seminars, int count)
{
	int r = 0;
	while (fscanf(in, " %s %[^0-9] %d", (seminars + r)->month, (seminars + r)->name, &(seminars + r)->part)!= EOF && (r < count))
		r++;
	fclose(in);
}

void display(seminar_t *seminars, int size)
{
	printf("Month     Seminar                          Participant\n");
	printf("------------------------------------------------------\n");
	
	for (int r = 0; r < size; r++)
		printf("%-9s %-30s      %4d\n", (seminars + r)->month, (seminars + r)->name, (seminars + r)->part);
}

int main(void)
{
	FILE *in = fopen("seminars.txt", "r");

	if (in == NULL)
		printf("Error has occured when opening the input file.\n");
	else
	{
		int count; 
		fscanf(in, "%d", &count);

		seminar_t *seminar;
		seminar = (seminar_t *)malloc(sizeof(seminar_t) * count); 
		
		readFromFile(in, seminar, count);

		bubbleSort(seminar, count);

		display(seminar, count);
		
	}
	return(0);
}
