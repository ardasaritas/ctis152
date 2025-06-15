/* Reads a list of integers, displays the content, 
finds the perfect numbers, writes into another file*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Reads a file into a specified array
void readFromFile(FILE *in, int array[], int *length);

// Displays the contens of the array
void display(int array[], int length);

// Finds out if a number is perfect or not
int isPerfect(int num);

/*Searches the array for perfect numbers, when found, 
records the count and stores them in another array*/
int findPerfect(int array[], int length, int out[]);

// Writes the content of the perfect number array into the file
void writeToFile(FILE *out, int outArr[], int length);


int main(void)
{
	FILE *in = fopen("numbersAQ1.txt","r");
	FILE *outp = fopen("perfect.txt","w");

	if (in == NULL)
		printf("Error has occured when opening file.\n");

	else
	{
		int numbers[20], perfect[20], reallength; 

		readFromFile(in, numbers, &reallength);

		printf("The list of numbers in the file:\n");
		for (int i = 0; i < reallength; i++)
			printf("%4d", *(numbers + i));	

		printf("\nThere are %d numbers is the array, %d of them are perfect numbers.\n", reallength, findPerfect(numbers, reallength, perfect));
		writeToFile(outp, perfect, findPerfect(numbers, reallength, perfect));
		
		fclose(in);
		fclose(outp);
	} 
return (0);
}

void readFromFile(FILE *in, int array[], int *length)
{
	while (fscanf(in, "%d", &array[*length]) != EOF)
		(*length)++;
}

void display(int array[], int length)
{
	for (int i = 0; i < length; i++)
		printf("%d", array[i]);
}

int isPerfect(int num)
{
	int sum = 1;

	for (int i = 2; i < num; i++)
		if (num % i == 0)
			sum += i;
		
	if (sum == num)
		return 1; 
	else return 0;
}

int findPerfect(int array[], int length, int out[])
{
	int k = 0;

	for (int i = 0; i < length; i++)
		if (isPerfect(array[i]))
			out[k++] = array[i];

	return (k);
}

void writeToFile(FILE *out, int outArr[], int length)
{
	for (int i = 0; i < length; i++)
		fprintf(out, "%d   ", outArr[i]);
}