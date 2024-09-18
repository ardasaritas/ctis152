/******
The program displays the weekly sales report of a restaurant, the weekly average itself, 
salesmen who have higher weekly average than the restaurant and the highest sale amount along
with the salesman who has made it, the day it was made and the value itself.
*******/
#include <stdio.h>
#include <stdlib.h>

// Minimum of salesman you want to see the information of
const int MINSALESMAN = 3; 

// Maximum of salesman you want to see the information of
const int MAXSALESMAN = 10;

// Displays information Mon-Fri
#define WEEK 5 

/*
If the resturant also works on weekend, delete lines [108-129] (switch statement),and add the following switch statement

switch (day)
        {
            case 0: 
            printf("The salesman %d has the highest sale amount, %d TL, on Monday.\n\n", index + 1, *(*(sales + index) + day)); 
            break;

            case 1: 
            printf("The salesman %d has the highest sale amount, %d TL, on Tuesday.\n\n", index + 1, *(*(sales + index) + day)); 
            break;
            
            case 2: 
            printf("The salesman %d has the highest sale amount, %d TL, on Wednesday.\n\n", index + 1, *(*(sales + index) + day)); 
            break;
            
            case 3: 
            printf("The salesman %d has the highest sale amount, %d TL, on Thursday.\n\n", index + 1, *(*(sales + index) + day)); 
            break;
            
            case 4: 
            printf("The salesman %d has the highest sale amount, %d TL, on Friday.\n\n", index + 1, *(*(sales + index) + day)); 
            break;

            case 5: 
            printf("The salesman %d has the highest sale amount, %d TL, on Saturday.\n\n", index + 1, *(*(sales + index) + day)); 
            break;

            case 6: 
            printf("The salesman %d has the highest sale amount, %d TL, on Sunday.\n\n", index + 1, *(*(sales + index) + day)); 
            break;
        }

*/
// Reads information of salesman. Reads according to the prompted number of salesman, sales array is also opened dynamically exactly at the prompted size
void readFromFile(FILE *in, int **sales, int numOfSalesman);

// Displays all the sales info
void displaySalesInfo(int **sales, int numOfSalesman);

// Calculates the weekly average of the restaurant by adding up all sales
double findAvg(int **sales, int numOfSalesman);

// Calculates a specific salesman's weekly average
double findSalesmanAvg(int *sales); 

// Searches for the maximum daily sale, returns the index of the salesman who made it and the day it was made
int findMaxSale(int **sales, int numOfSalesman, int *day); 

int main(void)
{
    FILE *in = fopen("sales.txt","r");

    if (in == NULL)
        printf("Error has occured when opening file.\n");
    else
    {
        int numOfSalesman, day, index; 
        double weeklyAverage; 

        printf("\n");

        // Data validation of salesman prompt
        do
        {
            printf("Enter the number of employees (%d-%d): ", MINSALESMAN, MAXSALESMAN); 
            scanf("%d", &numOfSalesman);
        } while (numOfSalesman > MAXSALESMAN || numOfSalesman < MINSALESMAN);
        
        
        int **sales;    
        sales = (int **)malloc(sizeof(int *) * numOfSalesman);

        for (int r = 0; r < numOfSalesman; r++)
            *(sales + r) = (int *)malloc(sizeof(int) * WEEK); 

        readFromFile(in, sales, numOfSalesman);
        displaySalesInfo(sales, numOfSalesman); 

        // Average calculations and displays
        weeklyAverage = findAvg(sales, numOfSalesman);
        printf("The weekly average sale amount of the restaurant: %0.2f TL\n\n", weeklyAverage);
        printf("Salesman info whose sale amount is above the average:\n");
        for (int i = 0; i < numOfSalesman; i++)
            if (findSalesmanAvg((*(sales + i))) > weeklyAverage)
                printf("Salesman No: %d, Average: %0.2f TL\n", i + 1, findSalesmanAvg((*(sales + i))));
        printf("\n");
        
        // Calculating and printing out the highest sale
        index = findMaxSale(sales, numOfSalesman, &day);
        switch (day)
        {
            case 0: 
            printf("The salesman %d has the highest sale amount, %d TL, on Monday.\n\n", index + 1, *(*(sales + index) + day)); 
            break;

            case 1: 
            printf("The salesman %d has the highest sale amount, %d TL, on Tuesday.\n\n", index + 1, *(*(sales + index) + day)); 
            break;
            
            case 2: 
            printf("The salesman %d has the highest sale amount, %d TL, on Wednesday.\n\n", index + 1, *(*(sales + index) + day)); 
            break;
            
            case 3: 
            printf("The salesman %d has the highest sale amount, %d TL, on Thursday.\n\n", index + 1, *(*(sales + index) + day)); 
            break;
            
            case 4: 
            printf("The salesman %d has the highest sale amount, %d TL, on Friday.\n\n", index + 1, *(*(sales + index) + day)); 
            break;
        }
        fclose(in);

        for (int j = 0; j < numOfSalesman; j++)
            free(*(sales + j)); 
        free(sales);
    }
    return(0);
}

void readFromFile(FILE *in, int **sales, int numOfSalesman)
{
    int i = 0, r; 
    while((i < numOfSalesman) && (fscanf(in, "%d", (*(sales + i) + 0)) != EOF))
    {
        for (r = 1; r < WEEK; r++)
            fscanf(in,"%d", (*(sales + i) + r));
        i++;
    }   
}

void displaySalesInfo(int **sales, int numOfSalesman)
{
    printf("\n      Weekly Sales Report\n"); 
    printf("*******************************\n");
    printf("         M    T    W    R    F\n"); 

    for (int i = 0; i < numOfSalesman; i++)
    {
        printf("S-%2d:", i + 1);
        for (int r = 0; r < WEEK; r++)
            printf(" %4d", *(*(sales + i) + r));
        printf("\n");
    }     
    
    printf("\n");
}

double findAvg(int **sales, int numOfSalesman)
{
    double sum = 0.0;

    for (int i = 0; i < numOfSalesman; i++)
        for (int r = 0; r < WEEK; r++)
         sum += *(*(sales + i) + r); 
    
    return (sum / (numOfSalesman * WEEK)); 
}

double findSalesmanAvg(int *sales)
{
    double sum = 0.0;
    for (int r = 0; r < WEEK; r++)
        sum += *(sales + r);
    return (sum / WEEK); 
}

int findMaxSale(int **sales, int numOfSalesman, int *day)
{
   double max = **sales;
   int index; 

    for (int i = 0; i < numOfSalesman; i++)
        for (int r = 0; r < WEEK; r++)
            if (*(*(sales + i) + r) > max)
            {
                max = *(*(sales + i) + r); 
                (*day) = r; 
                index = i; 
            }
    return(index); 
}
