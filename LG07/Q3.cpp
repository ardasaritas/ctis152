#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findWord(char *ptr);

int main(void)
{
	FILE *in = fopen("recipe.txt", "r"); 

	if (in == NULL)
		printf("Error has occured when opening file.\n"); 
	else
	{
		char string[15][190];

		int i = 0;
		while (fscanf(in, " %[^\n]", string[i]) != EOF)
			i++; 

		for (int r = 0; r < i; r++)
			printf("%2d. line contains %d words\n", r + 1, findWord(*(string + r)));
		
		fclose(in);
	}
	return(0);
}

int findWord(char *ptr)
{
	int cnt = 0; 

	for (int i = 0; i < strlen(ptr); i++)
		if (*(ptr + i) == ' ')
			cnt++; 
	return(cnt + 1);
}
