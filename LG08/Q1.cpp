// Reads words until the word END, capitalizes all and prints it out as a sentence
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Converts the passed string to uppercase
void convertToUpper(char *str); 

int main(void)
{
    char **string; 
    string = (char **)malloc(sizeof(char *) * 20); 

    for (int j = 0; j < 20; j++)
        *(string + j) = (char *)malloc(sizeof(char) * 20);

    int i = 0; 

    printf("\nEnter a word (or END to stop): "); 
    scanf("%s", *string);
    
    while (strcmp(*(string + i), "END") != 0)
    {
        i++;
        printf("Enter a word (or END to stop): "); 
        scanf("%s", *(string + i)); 
    } 

    printf("\nYou have entered %d words\n", i); 
    convertToUpper(*string);


    for (int r = 1; r < i; r++)
    {
        convertToUpper(*(string + r)); 
        strcat(*string, " "); 
        strcat(*string, *(string + r)); 
    }

    printf("\nThe sentence form in uppercase of the given words:\n"); 
    printf("%s\n\n", *string); 

    return(0); 

}

void convertToUpper(char *str)
{
    int i = 0; 
    while (*(str + i) != '\0')
    {
        if (*(str + i) <= 'z' && *(str + i) >= 'a')
            *(str + i) -= 'a' - 'A'; 
        i++;
    }    
}