#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <math.h>

int main(void)
{
	FILE *out = fopen("result.txt", "w");

	if (out == NULL)
		printf("Error has occurred when opening file.\n");

	else
	{
		int array[3][3];
		
		fprintf(out, "Element Name        Value    Address\n");
		fprintf(out, "------------------  ------   ---------\n");
		for (int i = 0; i < 3; i++)
			for (int k = 0; k < 3; k++)
				fprintf(out, "*(*(array + %d) + %d     %3.0f   %p\n", i, k, pow(3, i + k), (*(array + i) + k));
		printf("Successfull.\n");
		fclose(out);

	}
	return (0);
}
