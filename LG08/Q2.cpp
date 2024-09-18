// Finds a string's index of first occurance, prints it out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Finds the string sub's first occurence in string sent, returns index
int findFirstOccurance(char *sent, char *sub);

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

    if (findFirstOccurance(sentence, sub) == -1)
        printf("\nThe string you have searched is NOT in the sentence.\n"); 
    else 
        printf("\nThe first occurence of the string <%s> is %d\n", sub, findFirstOccurance(sentence, sub)); 

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