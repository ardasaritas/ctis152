#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu(); 

void randomFillArray(int **matrix, int m); 

void displayArray(int **matrix, int m); 

int searchValue(int **matrix, int m, int keyValue);

int main(void)
{
    int m, choice, value, count;

    printf("Please enter the dimension for the matrix: "); 
    scanf("%d", &m); 
    printf("\n"); 

    int **matrix; 
    matrix = (int **)malloc(sizeof(int *) * m); 

    for (int r = 0; r < m; r++)
        *(matrix + r) = (int *)malloc(sizeof(int) * m); 
    
    choice = menu(); 
    
    while(choice != 4)
    {
        switch (choice)
        {
            case 1: 
            srand(time(NULL));
            randomFillArray(matrix, m); 
            printf("\nArray filled with random numbers (20-199).\n\n");
            break;

            case 2: 
            displayArray(matrix, m); 
            printf("\n");
            break; 

            case 3: 
            printf("\nEnter the value to search: ");
            scanf("%d", &value); 

            count = searchValue(matrix, m, value);
            if (count == -1)
                printf("The array does NOT contain the value %d\n\n", value); 
            else 
            {
                printf("The number of occurences: %d\n\n", count); 
            }
        }
        choice = menu(); 
    }
    for (int j = 0; j < m; j++)
        free(*(matrix + j)); 
    free(matrix);
    
    return(0); 
}

int menu()
{
    int choice; 
    
    printf("        MENU\n"); 
    printf("1. Fill Array with Random numbers\n"); 
    printf("2. Display Array of Elements\n");
    printf("3. Display number of occurences of a value\n");
    printf("4. Exit\n");

    do
    {
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
    } while (choice > 4 || choice < 0);
    return(choice); 
}

void randomFillArray(int **matrix, int m)
{
    for (int r = 0; r < m; r++)
        for (int j = 0; j < m; j++)
            *(*(matrix + r) + j) = rand() % (180) + 20; 
}

void displayArray(int **matrix, int m)
{
    printf("\nContens of the array\n");
    printf("********************\n"); 

    for (int r = 0; r < m; r++)
    {
        for (int j = 0; j < m; j++)
            printf("%3d ", *(*(matrix + r) + j));
        printf("\n");
    }    
}

int searchValue(int **matrix, int m, int keyValue)
{
    int count = 0; 

    for (int r = 0; r < m; r++)
        for (int j = 0; j < m; j++)
            if (*(*(matrix + r) + j) == keyValue)
                count++; 
    if (count == 0)
        return(-1); 
    else return (count); 
}