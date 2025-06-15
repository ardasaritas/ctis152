#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void readFromFile(FILE *in, int *matrix);

void display(int *matrix, int length);

int isPrime(int number);

int findPrime(int *matrix, int length, int *out);

void writeToFile(FILE *out, int *prime, int length);

int main(void)
{
	FILE *in = fopen("numbers.txt", "r");
	FILE *out = fopen("prime.txt", "w");

	if (in == NULL)
		printf("Error when opening file.\n");
	else
	{
		int length;

		fscanf(in, "%d", &length);

		int *array;

		array = (int *) malloc(sizeof(int) * length);


		int *prime;

		prime = (int *)malloc(sizeof(int) * length);
		
		readFromFile(in, array);

		display(array, length);

		int count = findPrime(array, length, prime);

		printf("There are %d numbers in the array, %d of them are prime numbers.\n",length ,count );

		writeToFile(out, prime, count);

		free(array);
		free(prime);
	}
	return (0);
}

void readFromFile(FILE *in, int *matrix)
{
	int count = 0; 

	while (fscanf(in, "%d", matrix + count) != EOF )
		count++;	
}

void display(int *matrix, int length)
{
	for (int i = 0; i < length; i++)
		printf("%4d", *(matrix + i));
	printf("\n");
}

int isPrime(int number)
{
	
	if (number == 1)
		return 0;
	else
	{
		int divCnt = 0;
		for (int i = 1; i <= number; i++)
			if (number % i == 0)
				divCnt++;
		if (divCnt > 2)
			return (0);
		else return (1);
	}
}

int findPrime(int *matrix, int length, int *out)
{
	int count = 0;

	for (int i = 0; i < length; i++)
		if (isPrime(*(matrix + i)))
			*(out + count++) = *(matrix + i);

	return (count);
}

void writeToFile(FILE *out, int *prime, int length)
{
	for (int i = 0; i < length; i++)
		fprintf(out, "%d ", *(prime + i));
}
