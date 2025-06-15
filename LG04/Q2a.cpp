#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	char string[30]; 

	printf("Enter a word: ");
	scanf("%s", &string);

	printf("You have entered: %s\n", string);
	return 0;
}
