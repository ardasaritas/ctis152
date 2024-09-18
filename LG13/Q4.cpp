#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *str);

int main(void)
{
	char str[20];

	printf("Enter a word: ");
	scanf(" %s", str);

	if (isPalindrome(str))
		printf("The word <%s> is palindrome.\n", str);
	else
		printf("The word <%s> is NOT a palindrome.\n", str);

	return(0);
}

int isPalindrome(char *str)
{
	int size = strlen(str);

	if (size == 1)
		return(1);
	
	else
	{
		if (*(str + size - 1) == *str)
		{
			str[size - 1] = '\0';
			isPalindrome(str + 1);
		}
		else
			return(0);
	}
}
