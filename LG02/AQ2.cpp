// Interactively creates a sparse matrix with specified values and outputs it 
#include <stdio.h>
#include <stdlib.h>

/*Gets -in the following order- number of rows in the matrix, 
number of columns in the matrix, row index to put the value in,
column index to put the value in, the value itself.

Makes the validation of the entered value not being zero and
checks whether the indices are between the matrix boundaries that is created in the main dynamically.

After user enters how many values (s)he wants to enter, whether the matrix
is a sparse or not will also be checked*/
void getNonZeroElement(int **matrix, int rowSize, int colSize, int *rowIndex, int *colIndex, int *value);

void display(int **matrix, int rowSize, int colSize);

int main(void)
{
    int rowSizeMain, columnSize, columnIndex, rowIndexMain, enteredValue, numNonZero;

    
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rowSizeMain, &columnSize);

    // Dynamic Allocation 2-dim
    int **matrix;

    matrix = (int **) malloc(sizeof(int*) * rowSizeMain);

    for (int r = 0; r < rowSizeMain; r++)
        matrix[r] = (int *) malloc(sizeof(int) * columnSize);

    // Prompting and the data validation of non zero elements 
    do
    {
        printf("Enter number of non-zero elements: "); 
        scanf("%d", &numNonZero);
    } while (numNonZero >= rowSizeMain * columnSize / (double) 2);

    printf("\n");

    // Gets the elements from the user, assigns them into the suggested location one by one 
    for (int j = 0; j < numNonZero; j++)
    {
        getNonZeroElement(matrix, rowSizeMain, columnSize, &rowIndexMain, &columnIndex, &enteredValue);
        *(*(matrix + rowIndexMain) + columnIndex) = enteredValue;

    }
    
   
    printf("\nThe Sparse Matrix: \n\n");
    display(matrix, rowSizeMain, columnSize);
    printf("\n\n");

    
    for (int k = 0; k < rowSizeMain; k++)
        free(matrix[k]);  

    free (matrix); 
    return (0);    
}

void getNonZeroElement(int **matrix, int rowSize, int colSize, int *rowIndex, int *colIndex, int *value)
{
    
    printf("Enter row and column indexes and nonzero elements: ");
    scanf("%d %d %d", rowIndex, colIndex, value); 
    
    // Data validation of row & column index
    while (((*rowIndex) >= rowSize ) || ((*colIndex) >= colSize))
    {
        printf("\nInvalid indexes, please stay in boundaries.\nEnter row and column indexes again: ");
        scanf("%d %d", rowIndex, colIndex);
    }
    
    // Data validation of the supposed value
    while ((*value) == 0)
    {
        printf("Please enter a non-zero value: ");
        scanf("%d", value);
    } 
       
}

void display(int **matrix, int rowSize, int colSize)
{
     for (int i = 0; i < rowSize; i++)
    {
        for (int k = 0; k < colSize; k++)
            printf("[%d]  ", *(*(matrix + i) + k));
        printf("\n");
    }
}