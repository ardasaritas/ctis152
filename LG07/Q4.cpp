#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shortest(char string[][50], int size); 

int main(void)
{
	char temp[50], words[10][50];
	int i = 0; 

	while (strcmp(temp, "END") != 0)
	{
		strcpy(words[i], temp);
		i++;
		printf("Enter a word: ");
		scanf("%s", &temp);
	}

	printf("Shortest word: %s\n", words[shortest(words, i)]);
	printf("Length: %d", strlen(words[shortest(words, i)]));
	return(0);
}

int shortest(char string[][50], int size)
{
	int min = strlen(string[0]); 
	int index; 

	for (int r = 1; r < size; r++)
		if (strlen(string[r]) <= min)
		{
			min = strlen(string[r]);
			index = r;
		}
			
	return(index); 
}
