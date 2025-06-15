#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct 
{
    char name[10];
    char code[5]; 
}codes_t;

int searchCrs(codes_t codeList[], char key[]);

int main(void)
{
    FILE *in = fopen("course.txt","r"); 
    
    codes_t codeList[MAX] = {{"CS", "11"}, {"THM", "61"}, {"CTIS", "62"}, 
                             {"ECON", "32"}, {"HIST", "94"}, {"TURK", "95"}}; 
    
    codes_t courseCode[MAX * 2]; 
    char temp[3]; 

    int i = 0; 
    int index; 

    while(fscanf(in,"%s %s", (courseCode + i)->name , (courseCode + i)->code) != EOF)
        i++; 
    
    printf("\nOptic Codes\n***********\n"); 
    for (int r = 0; r < i; r++)
    {
        index = searchCrs(codeList, (courseCode + r)->name);
        if (index == -1)
            printf("%-4s %-3s -> ERROR\n", (courseCode + r)->name, (courseCode + r)->code); 
        else
        printf("%-4s %-3s -> %s%s\n", (courseCode + r)->name, (courseCode + r)->code, (codeList + index)->code, (courseCode + r)->code);
    }
    printf("\n");
    fclose(in); 
    return(0); 
}

int searchCrs(codes_t codeList[], char key[])
{
    int index = -1; 
    for (int r = 0; r < MAX; r++)
        if (strcmp(key, (codeList + r)->name) == 0)
            index = r; 
    return(index); 
}