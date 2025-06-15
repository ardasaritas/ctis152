#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int readFromText(FILE *in, int *array);

double findAvgStdDev(int *array, int length, double avg);

int main(void)
{
	FILE *in = fopen("numbersAQ1.txt", "r");

	if (in == NULL)
		printf("Error has occured when opening file.\n");
	else
	{
		int array[10], sum = 0;

		int length = readFromText(in, array);

		for (int i = 0; i < length; i++)
			sum += *(array + i);

		printf("The average of elements is: %0.2f\n", sum / (double) length);

		printf("The standard deviation of elements is: %0.2f\n", findAvgStdDev(array, length, sum / (double)length));
	}
	return (0);
}

int readFromText(FILE *in, int *array)
{
	int i = 0;

	while (fscanf(in, "%d", array + i) != EOF) // Exception Throw
		i++;
	
	return (i);
}

double findAvgStdDev(int *array, int length, double avg)
{
	double sum = 0;

	for (int i = 0; i < length; i++)
		sum += pow((*(array + i) - avg), 2);

	return (sqrt(sum / length));
}
