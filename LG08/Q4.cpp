// Replaces a selected string in the sentence with the user's input
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findFirstOccurance(char *sent, char *sub);

// Replaces the first occurance of the sub with rep by using the function above
void replaceFirstOccSub(char *sent, char *sub, char *rep);


int main(void)
{
	char *sentence;
	sentence = (char *)malloc(sizeof(char) * 200);

	char *sub;
	sub = (char *)malloc(sizeof(char) * 20);

	char *rep;
	rep = (char *)malloc(sizeof(char) * 20);

	printf("Enter a sentence: ");
	scanf("%[^'\n']", sentence);
	printf("Enter a string to search: ");
	scanf("%s", sub);
	printf("Enter a string to replace: ");
	scanf("%s", rep);

	replaceFirstOccSub(sentence, sub, rep);
	printf("\nNew sentence: %s\n", sentence);

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

void replaceFirstOccSub(char *sent, char *sub, char *rep)
{
	int pos = findFirstOccurance(sent, sub);

	if (pos != -1)
	{
		char temp[30] = ""; 
		strcpy(temp, sent + pos + strlen(sub)); 
		strcpy(sent + pos, rep); 
		strcat(sent, temp);
	}
	else printf("The sentence does not contain the string <%s>.\n", sub);
}
