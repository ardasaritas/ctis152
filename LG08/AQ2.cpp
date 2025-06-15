// Finds the last occurance of a string and prints the sentence until that string
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Finds the last occurance of a string in a given sentence
int findLastOccurance(char *sent, char *sub);

int main(void)
{
	char *sentence;
	sentence = (char *)malloc(sizeof(char) * 200);

	char *sub;
	sub = (char *)malloc(sizeof(char) * 20);

	printf("Enter a sentence: ");
	scanf("%[^'\n']", sentence);
	printf("Enter a string to search: ");
	scanf("%s", sub);

	if (findLastOccurance(sentence, sub) == 0)
		printf("\nThat is an empty string. Sorry.\n");
	else if (findLastOccurance(sentence, sub) == -1)
		printf("\nEntered string does not exist in the sentence.\n");
	else
	{
		strcpy(sentence + findLastOccurance(sentence, sub) - 1, "\0");
		printf("Result: %s\n", sentence);
	}
	
	free(sentence);
	free(sub);

	return(0);
}

int findLastOccurance(char *sent, char *sub)
{
	int k,
		sentLen = strlen(sent),
		subLen = strlen(sub);

	for (k = sentLen - subLen; k >= 0 ; k--)
		if (strncmp(sent + k, sub, subLen) == 0)
			return(k);
	return(-1);
}
