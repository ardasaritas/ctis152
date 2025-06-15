#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findFirstWord(char *sent, char *sub);

void delAllOcc(char *sent, char *sub);

int main(void)
{
	char *sentence = (char *)malloc(sizeof(char) * 200); 
	char *sub = (char *)malloc(sizeof(char) * 20); 

	printf("Enter a sentence: "); 
	scanf("%[^\n]", sentence); 

	printf("Enter a word: "); 
	scanf("%s", sub);

	delAllOcc(sentence, sub); 

	printf("Final format of the sentence: %s\n", sentence); 
	
    free(sentence); 
    free(sub);
    return(0);
}

int findFirstWord(char *sent, char *sub)
{
	int i, index = -1, sentlen = strlen(sent), sublen = strlen(sub); 

	for (i = 0; i <= sentlen - sublen; i++)
		if ((strncmp(sent + i, sub, sublen) == 0) &&
			(i == 0 || sent[i - 1] == ' ') &&
			(i == sentlen - sublen || sent[i + sublen] == ' '))
		{
			index = i; 
			return(index);
		}
	return(index);
}

void delAllOcc(char *sent, char *sub)
{
	int sentlen = strlen(sent), sublen = strlen(sub);

	int index = findFirstWord(sent, sub);

	while (index != -1)
	{
		strcpy(sent + index, sent + index + sublen);
		index = findFirstWord(sent, sub);
	}
}
