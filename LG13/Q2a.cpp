#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createBinaryFile(FILE *out);

int main(void)
{
	FILE *out = fopen("numbers.bin", "wb");
	createBinaryFile(out);
	fclose(out);
	
	FILE *in = fopen("numbers.bin", "rb");
	int flag;

	printf("Please enter the number of items to be read: ");
	scanf("%d", &flag);

	int *ptr = (int *)malloc(sizeof(int) * flag);
	fread(ptr, sizeof(int), flag, in);

	for (int j = 0; j < flag; j++)
		printf("%d. %d\n", j + 1, *(ptr + j));
	
	return(0);
}

void createBinaryFile(FILE *out)
{
	int k;

	srand(time(NULL));

	for (int i = 0; i < 250; i++)
	{
		k = rand() % 5001;
		fwrite(&k, sizeof(int), 1, out);
	}
}
