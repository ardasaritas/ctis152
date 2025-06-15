#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * concetenateStrings(char array[][10], int numOfStrings)
{
    int totalLength = 0; 
    for (int i = 0; i < numOfStrings; i++)
        totalLength += strlen(array[i]) + 1; // For spaces and null character at the end

    char *result;
    result = (char *)malloc(sizeof(char) * totalLength); 

    for (int i = 0; i < numOfStrings; i++) 
    {
        strcat(result, array[i]);
        strcat(result, " ");
    }
    return result; 
}

int main(void)
{
    char days[7][10] = {"Monday", "Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
     
    int numOfStrings = sizeof(days) / sizeof(days[0]);
    
    char *result = concetenateStrings(days, numOfStrings);
    printf("All days a string: %s\n", result);

    return 0;
}
