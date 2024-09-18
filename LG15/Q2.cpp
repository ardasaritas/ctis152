// Prints the palindromes from a file using stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack_char.h"

int isLetter(char ch);

void removePunct(char *str);

int isPalindrome(char *str); 

int main(void)
{
    FILE *in = fopen("palindrome.txt","r");

    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        char *str = (char *)malloc(sizeof(char) * 50);
        char *temp = (char *)malloc(sizeof(char) * 50);
        while(fscanf(in," %[^\r]", str) != EOF)
        {
            strcpy(temp, str); 
            for (int i = strlen(str); i >= 0; i--)
                *(str + i) = toupper(*(str + i));
            removePunct(str);
            if (isPalindrome(str))
                printf("%s\n", temp);         
        }
        fclose(in);
        free(str);
        free(temp);
    }
    return(0); 
}

int isLetter(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return (1);
    else    
        return 0;
}

void removePunct(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        if (!isLetter(*(str + i)))
        {
            strcpy(str + i, str + i + 1);
            len--;
            i--;
        }
}

int isPalindrome(char *str)
{
    stackk_t s; 
    initializeS(&s); 

    for (int i = 0; i < strlen(str); i++)
        push(&s, str[i]);
    
    int k = 0;

    while (!isEmptyS(&s))
        if(str[k] != pop(&s)) 
            return (0);
        else k++;

    return (1); 
}