#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	FILE *in = fopen("words1.txt", "r"); 

	if (in == NULL)
		printf("Error!"); 
	else
	{
		char string[30][30];
		int i = 0;

		printf("The words in the file\n");
		printf("*********************\n");

		while (fscanf(in, "%s", *(string + i++)) != EOF);

		for (int k = 0; k < (i - 1); k++)
			printf("%s\n", string[k]);
	}

	return 0;
}
