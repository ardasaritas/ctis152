// Prints the elements' pointer notation, value and address in a file called sequence.txt
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>


int main(void)
{
	FILE *out = fopen("sequence.txt", "w");

	if (out == NULL)
		printf("An error has occured when opening the file.\n");
	else
	{
		double array[6];
		
		fprintf(out, "Element Name     Value     Address\n");
		fprintf(out, "-------------     -----     --------\n");

	
		for (int i = 0; i < 6; i++)
		{
			*(array + i) = pow(9,(i + 1));
			fprintf(out, "* (nums + %d)    %6.0f     %p\n", i, *(array + i), array + i);
		}
		
		printf("Successful! Please see sequence.txt file for the output.\n");
		fclose(out);
	}
	return(0);
}
