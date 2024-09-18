/******
Reads the number of cities to display information ONLY about them. 
Reads all cities' information from a file to a dyna. 2-dim.
Displays the temperatures on the screen, calculates the coldest one, 
displays it accordingly. 
*******/
#include <stdio.h>
#include <stdlib.h>

#define COL 7

// Reads the file into a dyna. 2-dim
void readFromFile(FILE *in, int **cities, int numOfCities);

// Displays all the temparatures
void display(int **cities, int numOfCities); 

// Finds the coldest day ,returns row-column indexes and the temparature itself
int findColdestDay(int **cities, int numOfCities, int *rowInd, int *colInd); 

int main(void)
{
    FILE *in = fopen("weather.txt","r"); 

    if (in == NULL)
        printf("Error has occured when opening file.\n");
    else
    {
        int numOfCities; 
        // Data validation of number of cities to be displayed
        do
        {
            printf("How many city will be displayed in the report? ");
            scanf("%d", &numOfCities);
        } while (numOfCities > 15 || numOfCities <= 0);
        
        int **cities; 
        cities = (int **)malloc(sizeof(int *) * numOfCities); 

        for (int r = 0; r < numOfCities; r++)
            *(cities + r) = (int *)malloc(sizeof(int) * COL);
        
        readFromFile(in, cities, numOfCities); 
        display(cities, numOfCities); 
        
        int rowInd, colInd; 
        int temparature = findColdestDay(cities,  numOfCities, &rowInd, &colInd); 
 
        switch (colInd)
        {
            case 0: 
            printf("City %d is the coldest one with the temparature %d on Monday.\n", rowInd + 1, temparature); 
            break;

            case 1: 
            printf("City %d is the coldest one with the temparature %d on Tuesday.\n\n", rowInd + 1, temparature); 
            break;
            
            case 2: 
            printf("City %d is the coldest one with the temparature %d on Wednesday.\n\n", rowInd + 1, temparature); 
            break;
            
            case 3: 
            printf("City %d is the coldest one with the temparature %d on Thursday.\n\n", rowInd + 1, temparature); 
            break;
            
            case 4: 
            printf("City %d is the coldest one with the temparature %d on Friday.\n\n", rowInd + 1, temparature); 
            break;

            case 5: 
            printf("City %d is the coldest one with the temparature %d on Saturday.\n\n", rowInd + 1, temparature); 
            break;

            case 6: 
            printf("City %d is the coldest one with the temparature %d on Sunday.\n\n", rowInd + 1, temparature); 
            break;
        }
        fclose(in);
        
        for (int r = 0; r < numOfCities; r++)
            free(*(cities + r)); 
        free (cities);
        
    }
    return(0);
}

void readFromFile(FILE *in, int **cities, int numOfCities)
{
    int i = 0; 
    while((fscanf(in, "%d", (*(cities + 0) + i)) != EOF) && (i < numOfCities))
    {
        for (int r = 1; r < COL; r++)
            fscanf(in, "%d", (*(cities + i) + r)); 
        i++;
    }
}

void display(int **cities, int numOfCities)
{
    printf("\nCity   M    T    W    R    F    S    S\n");
    printf("----  ---  ---  ---  ---  ---  ---  ---\n");
    
    for (int i = 0; i < numOfCities; i++)
    {
        printf("%4d", i + 1); 
        for (int r = 0; r < COL; r++)
            printf("  %3d", *(*(cities + i) + r));
        printf("\n");
    }    
}

int findColdestDay(int **cities, int numOfCities, int *rowInd, int *colInd)
{
   int min = **cities; 
   
    for (int i = 0; i < numOfCities; i++)
        for (int r = 0; r < COL; r++)
            if (*(*(cities + i) + r) < min)
            {
                min = *(*(cities + i) + r);
                (*rowInd) = i; 
                (*colInd) = r; 
            }    
                
    return(min);
}