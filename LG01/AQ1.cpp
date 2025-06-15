/* Reads numbers from a text file into a two-dim, if square, finds the summation of minor.
If not, Finds the product of a specified row that is acquired from the user.*/
#include <stdio.h>

#define COL 5
#define ROW 30

// Displays a matrix
void display(int matrix[][COL], int rowLength); 

// Finds the summation of minor diagonal of a square matrix
int sumOfMinor(int matrix[][COL], int rowLength); 

// Finds the products of a specified row of a non-square matrix
int productOfRow(int matrix[][COL], int specifiedRow); 

int main(void)
{
    //FILE *in = fopen("input1.txt","r");
    FILE *in = fopen("input2.txt","r"); // To use 2nd input file

    if (in == NULL)
        printf("Error has occured when opening file.");
    else
    {
        int matrix[ROW][COL], rowCnt, rowNum, result;

        // Reading the numbers from the file to the matrix, also counting rows
        rowCnt = 0;
        while (fscanf(in, "%d", &matrix[rowCnt][0]) != EOF)
        {
            for(int k = 1; k < 5; k++)
                fscanf(in,"%d", &matrix[rowCnt][k]);
            rowCnt++;
        }

        display(matrix, rowCnt);
        
        if (rowCnt == COL)
        {
            printf("The matrix is a SQUARE matrix.\n"); 
            printf("The summation of the elements on the Minor Diagonal is: %d\n", sumOfMinor(matrix, rowCnt));
        }    
       else 
        {
            printf("The matrix is not a SQUARE matrix.\n");
            printf("Enter the row number: ");
            scanf("%d", &rowNum);
            
            printf("\nThe product of the elements on the given row: %d\n", productOfRow(matrix, rowNum));
        }     
    fclose(in);
    }

return(0);
}

void display(int matrix[][COL], int rowLength)
{
    for (int i = 0; i < rowLength; i++)
    {
        for (int k = 0; k < COL; k++)
            printf("%2.d  ", matrix[i][k]);
        printf("\n");
    }    
        
}

int sumOfMinor(int matrix[][COL], int rowLength)
{
    int sum = 0; 
    
        for (int k = 0; k < COL; k++)
            sum += matrix[k][rowLength - 1 - k];

    return (sum);
}

int productOfRow(int matrix[][COL], int specifiedRow)
{
    int product = 1;
     
    for (int i = 0; i < COL; i++)
        product *= matrix[specifiedRow - 1][i];

    return (product);
}