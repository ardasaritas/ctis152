/*
Displays the team survivor, searches for people, displays their awards.
Shows each team's points and contrasts them to eachother.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40

typedef struct 
{
    char competitionType[20]; 
    int points; 
}competitor_t;

typedef struct 
{
    char name[20];
    char surname[20];
    int age; 
    char gender; 
    int impunityCount; 
    char teamColor;
    competitor_t competition; 
}survivor_t;

int readFile(FILE *in, survivor_t *survivors, int size);

void swapStr(char *str1, char *str2);

void bubbleSort(survivor_t *survivors, int size);

int binarySearch(survivor_t *arr, char string[], int size);

void calcPoints(survivor_t *survivors, int *sumR, int *sumB, int size);

void display(survivor_t *survivors, int size); 

void formatName(char a[], char b[]);

int main(void)
{
    FILE *in = fopen("survivors.txt","r");

    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        survivor_t *survivors;
        survivors = (survivor_t *)malloc(sizeof(survivor_t) * MAX); 

        int actSize = readFile(in, survivors, MAX); 

        bubbleSort(survivors, actSize); 
        display(survivors, actSize);
        
        char string1[20], string2[20];
        printf("Enter the survivor name and surname to search: ");
        scanf("%s %s", string1, string2); 
        formatName(string1, string2);

        // Binary search does not work
        if(binarySearch(survivors, string1, actSize) == -1 && binarySearch(survivors, string2,actSize) == -1)
            printf("%s %s is not in the survivor list.\n\n", string1, string2);
        else    
            printf("%s %s got the impunity award for %d times.\n\n", string1, string2, (survivors + binarySearch(survivors, string1, actSize))->impunityCount);
        
        int sumR = 0, sumB = 0;
        calcPoints(survivors, &sumR, &sumB, actSize);

        printf("Red team collected %d points\n", sumR);
        printf("Blue team collected %d points\n", sumB);

        if (sumR > sumB)
            printf("Red team is the winner.\n\n");
        else    
            printf("Blue team is the winner.\n\n");
        
        return(0);
    }
}

int readFile(FILE *in, survivor_t *survivors, int size)
{
    int i = 0;
    while(fscanf(in," %s %s %d %c %d %c %s %d", (survivors + i)->name, (survivors + i)->surname, &(survivors + i)->age, &(survivors + i)->gender, &(survivors + i)->impunityCount, &(survivors + i)->teamColor, (survivors + i)->competition.competitionType, &(survivors + i)->competition.points) != EOF && (i < size))
        i++;
    return(i);
}

void swapStr(char *str1, char *str2)
{
    char temp[MAX];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp); 
}

void bubbleSort(survivor_t *survivors, int size)
{
    int sorted, pass; 
    pass = 1; 
    do
    {
        sorted = 1;
        for (int r = 0; r < size - pass - 1; r++)
            if (strcmp((survivors + r)->name,(survivors + r + 1)->name) > 0)
            {
                swapStr((survivors + r)->name,(survivors + r + 1)->name); 
                sorted = 0;
            }
        pass++;
    } while (!sorted); 
}

int binarySearch(survivor_t *arr, char string[], int size) 
{ 
    int start = 0, finish = size - 1;

    int mid;

    while(start <= finish)
    {
        mid = (start + finish) / 2;

        if (strcmp(string, (arr + mid)->name) == 0)
        return(mid);

        else if (strcmp(string, (arr + mid)->name) < 0)
        finish = mid - 1;

        else if (strcmp(string, (arr + mid)->name) > 0)
        start = mid + 1; 
    }
    return(-1);
} 

void calcPoints(survivor_t *survivors, int *sumR, int *sumB, int size)
{
    for (int r = 0; r < size; r++)
        if ((survivors + r)->teamColor == 'R')
            (*sumR)+=(survivors + r)->competition.points;
        else
            (*sumB)+=(survivors + r)->competition.points;
}

void display(survivor_t *survivors, int size)
{
    printf("Name       Surname    Age   Gender   Impuity Count   Team Color   Competition Type    Score\n");
    printf("-------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < size; i++)  
        printf("%-10s %-10s  %-3d     %c           %d             %c           %-10s         %3d\n", (survivors + i)->name, (survivors + i)->surname, (survivors + i)->age, (survivors + i)->gender, (survivors + i)->impunityCount, (survivors + i)->teamColor, (survivors + i)->competition.competitionType, (survivors + i)->competition.points);
    printf("\n");
}

void formatName(char a[], char b[])
{
    if (*a <= 'z' && *a >= 'a')
        *a -= 'a' - 'A'; 

    for (int r = 0; r < strlen(b); r++)
        if (*(b + r) <= 'z' && *(b + r) >= 'a')
            *(b + r) -= 'a' - 'A';
}