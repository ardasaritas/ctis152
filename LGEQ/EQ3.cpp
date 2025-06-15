/*
Program decides whether given variables are valid or not. 
If not, displays a valid option for that invalid variable. 
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTHVAR 30 // Maximum length of a given variable

void readFile(FILE *in, char **variables, int flag);

void validateAndDisplay(char **variables, int flag);

int countBlank(char *string);

int countPunc(char *string);

int isValid(char *variable); 

void newFormat(char *invalid);

int main(void)
{
    FILE *in = fopen("VarNames.txt","r");

    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        int flag; 
        fscanf(in,"%d", &flag); 

        char **variables; 
        variables = (char **)malloc(sizeof(char *) * flag); 

        for (int r = 0; r < flag; r++)
            *(variables + r) = (char *)malloc(sizeof(char) * MAXLENGTHVAR); 
        
        readFile(in, variables, flag); 
        validateAndDisplay(variables, flag); 
    }
    return(0);
}

void readFile(FILE *in, char **variables, int flag)
{
    int i = 0; 
    while (fscanf(in," %[^\r]", variables[i]) != EOF && (i < flag))
        i++; 
        
    fclose(in);
}

void validateAndDisplay(char **variables, int flag)
{
    printf("\nVARIABLES          STATUS      NEW FORMAT\n"); 
    printf("---------          --------    ----------\n");

    for (int j = 0; j < flag; j++)
        if (isValid(*(variables + j)))
            printf("%-15s    VALID       %s\n", *(variables + j), *(variables + j)); 
        else 
        { 
            printf("%-15s    INVALID", *(variables + j));
            newFormat(*(variables + j));
            printf("     %s\n", *(variables + j)); 
        }
    printf("\n");
}

int countBlank(char *string)
{
    int countOfBlanks = 0;
    for (int i = 0; i < strlen(string); i++)
        if (*(string + i) == ' ')
            countOfBlanks++; 
    return(countOfBlanks); 
}   

int countPunc(char *string)
{
    int countOfPunc = 0;
    for (int i = 0; i < strlen(string); i++)
        if (ispunct(*(string + i)) != 0)
            countOfPunc++; 
    return(countOfPunc); 
}

int isValid(char *variable)
{
    if (*variable >= '0' && *variable <= '9')
        return(0); 
    else if (countBlank(variable) > 0 || countPunc(variable) > 0)
        return(0); 
    else return(1); 

}

void newFormat(char *invalid)
{
    if (*invalid >= '0' && *invalid <= '9')
    {
        char temp = *invalid;
        strcpy(invalid, invalid + 1); 
        *(invalid + strlen(invalid)) = temp;
    }
    
    for (int r = 0; r < strlen(invalid); r++)
        if (*(invalid + r) == ' ' || ispunct(*(invalid + r)))
            *(invalid + r) = '_';
}