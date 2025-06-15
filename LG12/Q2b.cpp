/*****
Finds the count occurences of a string in a sentence.
Uses recursive findOccurences algorithm.
****/
#include <stdio.h>
#include <string.h>

int findOccurences(char *str, char *sub, int num)
{
    if (num == strlen(str) - strlen(sub) + 1)
        return(0); 
    else if (strncmp(str + num, sub, strlen(sub)) == 0)
    {
        num++;
        return(1 + findOccurences(str, sub, num)); 
    }
    else 
    {
        num++;
        return(findOccurences(str, sub, num));
    }
}

int main(void)
{
    char ch[20], string[100]; 

    printf("Enter a sentence: "); 
    scanf("%[^\n]", string); 

    printf("Enter a word to search: "); 
    scanf(" %s", ch); 

    printf("\nThe word <%s> has occurred %d times.\n", ch, findOccurences(string, ch, 0));
    return(0);
}