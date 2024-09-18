/*****
Finds the count occurences of a character in a string, adds both upper and lowercase to the final result.
Uses recursive findOccurences algorithm.
*****/
#include <stdio.h>

int findOccurences(char *str, char ch)
{
    if (*str == '\0')
        return(0); 
    else if (((*str <= 'z' && *str >= 'a') && ((*str == ch)) || (*str == ch + 'A' - 'a')) || 
              (*str <= 'Z' && *str >= 'a') && ((*str == ch)) || (*str == ch + 'a' - 'A'))
        return(1 + findOccurences((str + 1), ch)); 
    else 
        return(findOccurences(str + 1, ch));
}

int main(void)
{
    char ch, string[50]; 

    printf("Enter a string: "); 
    scanf("%[^\n]", string); 

    printf("Enter a character to search: "); 
    scanf(" %c", &ch); 

    printf("\n%s\nCharacter %c has occurred %d times.\n", string, ch, findOccurences(string, ch));
    return(0);
}