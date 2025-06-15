// Reads an integer list from a file, displays min-max, calculates avg without them

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Reads a list to an array
void readList(FILE *in, int array[], int *length); 

// Finds the min and max of an array
void findMinMax(int array[], int length, int *min, int *max);

// Finds the min and max of an array excluding min and max
double findAvgExcMinMax(int array[], int length, int min, int max);

int main(void)
{
	FILE *in = fopen("clusternumbers.txt", "r");

	if (in == NULL)
		printf("Error has occured when opening file.\n");
	else
	{
		int array[20], length = 0, min, max;

		readList(in, array, &length);

		findMinMax(array, length, &min, &max);

		printf("Min Value: %d\nMax value: %d\n", min, max);
		
		printf("Average excluding the minimum and maximum value: %0.2f\n", findAvgExcMinMax(array, length, min, max));

		fclose(in);

	}
	return(0);
}

void readList(FILE *in, int array[], int *length)
{
	
	while (fscanf(in, "%d", &array[*length]) != EOF)
		(*length)++;
}

void findMinMax(int array[], int length, int *min, int *max)
{
	int i, k;

	(*min) = array[0];
	
	for (i = 0; i < length; i++)
		if (array[i] < (*min))
			(*min) = array[i];
		


	(*max) = array[0];

	for (k = 0; k < length; k++)
		if (array[k] > (*max))
			(*max) = array[k];
}

double findAvgExcMinMax(int array[], int length, int min, int max)
{
	int sum = 0; 

	for (int i = 0; i < length; i++)
		sum += array[i];

	sum = sum - (min + max);

	return( (double)sum / (length - 2));
}	
