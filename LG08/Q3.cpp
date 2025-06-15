// Deletes a selected string from the sentence
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findFirstOccurance(char *sent, char *sub);

void deleteFirstOccurence(char *sent, char *sub);


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

	deleteFirstOccurence(sentence, sub);
	printf("\nThe sentence after deletion: %s\n", sentence);

	return(0);
}

int findFirstOccurance(char *sent, char *sub)
{
	int k,
		sentLen = strlen(sent),
		subLen = strlen(sub);

	for (k = 0; k <= sentLen - subLen; k++)
		if (strncmp(sent + k, sub, subLen) == 0)
			return(k);
	return(-1);
}

void deleteFirstOccurence(char *sent, char *sub)
{
	int pos = findFirstOccurance(sent, sub); 

	if (pos != -1)
		strcpy(sent + pos, sent + pos + strlen(sub));
	else printf("The sentence does not contain the string <%s>.\n", sub); 
}
