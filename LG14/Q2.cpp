#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "stack_string.h"

int main(void)
{
	FILE *in = fopen("authors.txt", "r");
	
	if (in == NULL)
		printf("Error!");
	else
	{
		char temp[STR_SIZE] = "";
		stackk_t S;

		initializeS(&S);

		while (fscanf(in, " %[^\r]", temp) != EOF)
			push(&S, temp);

		printf("Authors in reverse order\n");
		printf("************************\n");
	
		while (!isEmptyS(&S))
			printf("%-50s\n", pop(&S));
		printf("\n");
		return(0);
	}
	return(0);
}

