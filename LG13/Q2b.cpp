#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createBinaryFile(FILE *out, int A[]);

int main(void)
{
	FILE *out = fopen("numbers.bin", "wb");
	int A[250];

	createBinaryFile(out, A);
	fclose(out);

	FILE *in = fopen("numbers.bin", "rb");
	int flag;

	printf("Please enter the number of items to be read: ");
	scanf("%d", &flag);

	for (int j = 0; j < flag; j++)
		printf("%d. %d\n", j + 1, A[j]);

	return(0);
}

void createBinaryFile(FILE *out, int A[])
{
	srand(time(NULL));

	for (int i = 0; i < 250; i++)
		A[i] = rand() % 5001;

	fwrite(A, sizeof(int), 250, out);
}
