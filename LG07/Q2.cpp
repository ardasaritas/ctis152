#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrLen(char *str);

int main(void)
{
	FILE *in = fopen("words.txt", "r"); 
	FILE *out = fopen("results.txt", "w"); 

	if (in == NULL)
		printf("Error has occured when opening file.\n");
	else
	{
		char str[100]; 

		while (fscanf(in, "%s", str) != EOF)
			fprintf(out, "%s - %d\n", str, myStrLen(str));
			
		fclose(in);
		fclose(out); 
	}
	return(0);
}

int myStrLen(char *str)
{
	char *tp;
	tp = str;

	while (*tp != '\0')
		*tp++;
	return(tp - str);
}
