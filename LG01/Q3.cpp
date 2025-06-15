// Reads positive numbers, finds the count of even and odd ones
#include <stdio.h>

// Reads the positive numbera and stores in an array, returns count 
void fillArray(int array[], int *count);

// Finds and returns the count of even and odd numbers in the array
void findEvenOdd(int array[], int length, int *num1, int *num2);

int main(void)
{
    int posNumbers[100], count = 0, evenCount, oddCount;
    
    fillArray(posNumbers, &count);
    findEvenOdd(posNumbers, count, &evenCount , &oddCount);

    printf("There are %d even numbers.\n\n", evenCount);
    printf("There are %d odd numbers.\n", oddCount);
    
    return (0);
}

void fillArray(int array[], int *count)
{
  
    printf("Enter a positive number: ");
    scanf("%d", &array[(*count)]);

    while (array[(*count)] > 0)
    {
        (*count)++;
        printf("Enter a positive number: ");
        scanf("%d", &array[(*count)]);   
    }
    printf("\n");
}

void findEvenOdd(int array[], int length, int *num1, int *num2)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] % 2 == 0)
            (*num1)++;
        else    
            (*num2)++;
    }
}
