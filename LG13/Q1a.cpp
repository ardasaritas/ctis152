#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE *in = fopen("nums.bin", "rb");
	if (in == NULL)
		printf("Error!");
	else
	{
		int ptr[25]; 

		int size = fread(ptr, sizeof(int), 25, in);
		
		for (int i = 0; i < 25; i++)
			printf("%d ", *(ptr + i));
		printf("\n\nThere are %d numbers in the file.\n", size);
	}
	return(0);
}
