#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
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

	do
	{
		printf("Please enter the order of the item to be read: ");
		scanf("%d", &flag);
	} while (flag > 250 || flag <= 0);

	printf("%d. %d\n",flag, A[flag]);

	return(0);
}

void createBinaryFile(FILE *out, int A[])
{
	srand(time(NULL));

	for (int i = 0; i < 250; i++)
		A[i] = rand() % 5001;

	fwrite(A, sizeof(int), 250, out);
}
