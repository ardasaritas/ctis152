#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void input(int *matrix, int length);

double findGrade(int *matrix, int length);

int main(void)
{
	int n;


	printf("How many grades? ");
	scanf("%d", &n);
	
	if (n > 0)
		printf("Enter %d grades: ", n);
	
	while (n > 0)
	{
		int *matrix;

		matrix = (int *)malloc(sizeof(int)*n);

		input(matrix, n);

		printf("The %%40 of the total grade : %.2f\n", findGrade(matrix, n));

		printf("\nHow many grades? ");
		scanf("%d", &n);

		if (n > 0)
			printf("Enter %d grades: ", n);
	}
	return (0);
}

void input(int *matrix, int length)
{
	int i = 0; 

	for (i = 0; i < length; i++)
		scanf("%d", (matrix + i));
}

double findGrade(int *matrix, int length)
{
	int sum = 0, i; 

	for (i = 0; i < length; i++)
		sum += *(matrix + i);

	return(sum * 0.4);
}
