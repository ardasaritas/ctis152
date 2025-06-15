#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10 

int readFile(FILE* in, char **matrix);

void displayWord(char **ptr, int k);

void displayWordSpecCol(char **matrix, int keyCol, int wordCount); 

int main(void)
{
	FILE *in = fopen("words2.txt", "r");

	if (in == NULL)
		printf("Error!");
	else
	{
		int flag, count, key; 
		fscanf(in, "%d", &flag);

		char **matrix;

		matrix = (char **)malloc(sizeof(char *) * flag);
		
		for (int r = 0; r < flag; r++)
			*(matrix + r) = (char *)malloc(sizeof(char) * LENGTH);

		count = readFile(in, matrix);

		printf("The number of words in the text file: %d\n", count);
		printf("\n WORDS\n");
		printf("*******\n");

		for (int k = 0; k < count; k++)
			displayWord(matrix, k);

		printf("Enter the column number: ");
		scanf("%d", &key); 

		displayWordSpecCol(matrix, key, count); 
	
		for (int r = 0; r < count; r++)
			free(*(matrix+r)); 

		free(matrix); 
		fclose(in); 
	}
	return (0);
}

int readFile(FILE* in, char **matrix)
{
	int count = 0;

	while (fscanf(in, "%s", *(matrix + count)) != EOF)
		count++;

	return count; 
}

void displayWord(char **ptr, int k)
{
	printf("%s\n", *(ptr + k)); 
}

void displayWordSpecCol(char **matrix, int keyCol, int wordCount)
{
	int i; 

	for(i = 0; i < wordCount; i++)
		printf("%c", *(*(matrix + i) + (keyCol -1)));
	printf("\n");
}
