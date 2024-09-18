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
	int m, n, count = 0;

	
	printf("Please enter the order of the item to be read from the end: ");
	scanf("%d", &m);

	printf("Please enter the order of the item to be read from its current position: ");
	scanf("%d", &n);
	
	printf("%d. %d\n", 250 - m, A[250 - m]);
	printf("%d. %d\n", 250 - m - n, A[250 - m - n]);

	return(0);
}

void createBinaryFile(FILE *out, int A[])
{
	srand(time(NULL));

	for (int i = 0; i < 250; i++)
		A[i] = rand() % 5001;

	fwrite(A, sizeof(int), 250, out);
}
