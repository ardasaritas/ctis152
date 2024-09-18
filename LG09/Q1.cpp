#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findAllOccur(char *sent, char *sub, int pos[]); 

int main(void)
{
    char *sentence = (char *)malloc(sizeof(char)*300); 
    char *sub = (char *)malloc(sizeof(char)*40); 
    
    int pos[20]; 

    printf("Enter a sentence: "); 
    scanf("%[^\n]", sentence); 

    printf("Enter a string to search: "); 
    scanf(" %[^\n]", sub); 

    int size = findAllOccur(sentence, sub, pos);
    
    if (size != 0)
    {
        printf("All occurences of the string <%s> :\nIndex(es): ", sub); 
        for (int r = 0; r < size; r++)
            printf("%d ", pos[r]);
        printf("\n"); 
    }
    else
    printf("The string <%s> couldn't be found.\n", sub); 
    free(sentence);
    free(sub);
    return(0);
}

int findAllOccur(char *sent, char *sub, int pos[])
{
    int count = 0, 
        sentlen = strlen(sent), 
        sublen = strlen(sub); 

    for (int r = 0; r <= sentlen - sublen; r++)
        if (strncmp(sent + r, sub, sublen) == 0)
            pos[count++] = r; 
    return(count); 
}
