#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main(void)
{
	char ptr[20];
	
	printf("Enter a sentence: "); 
	scanf("%[^\n]", &ptr); 
	printf("Sentence is: %s\n", &ptr); 

	return(0);
}
