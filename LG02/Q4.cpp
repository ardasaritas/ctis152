/* Reads an array of n integers (n is max 500) until sentinel (-99) entered. Prints the total duplicates and 
also writes the duplicate elements into a file*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	FILE *out = fopen("duplicateElements.txt", "w");

	if (out == NULL)
		printf("Error has occured when opening output file.\n");
	else
	{
		int count = 0, num[500], cntDup = 0;

		while (count < 500 && num[count++] != -99)
		{
			printf("Enter a number: ");
			scanf("%d", &num[count]);
		}

		for (int i = 0; i < count - 1; i++)
			for (int j = i + 1; j < count; j++)
				if (num[i] == num[j])
				{
					cntDup++;
					fprintf(out, "%2d\n", num[i]);
				}

		printf("Total number of duplicate elemtns found in the array --> %d", cntDup);
		
		fclose(out);
	}
return (0);
}
