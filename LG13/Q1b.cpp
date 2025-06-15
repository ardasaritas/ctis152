#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *in = fopen("nums.bin", "rb");
	if (in == NULL)
		printf("Error!");
	else
	{
		int *ptr;
		int size;
		
		fseek(in, 0, SEEK_END);
		size = ftell(in) / sizeof(int);

		ptr = (int *)malloc(sizeof(int) * size);

		rewind(in);
		fread(ptr, sizeof(int), size, in);

		for (int i = 0; i < size; i++)
			printf("%d ", *(ptr + i));
		printf("\n\nThere are %d numbers in the file.\n", size);
	}
	return(0);
}
