// Swaps positive integers
#include <stdio.h>

// Swaps two integers "call by reference" method
void swap(int *a, int *b);

int main(void)
{
    int num1, num2 , flag = 0; 

    // Input and data validation of first number
    printf("Enter first number: ");
    scanf("%d", &num1);

    while (num1 < 0)
    {
    printf("First number must be positive.\n");
    printf("Enter first number: ");
    scanf("%d", &num1);
    }
    
    printf("\n");

    // Input and data validation of second number
    printf("Enter second number: ");
    scanf("%d", &num2);

    while (num2 < 0)
    {
    printf("Second number must be positive.\n");
    printf("Enter second number: ");
    scanf("%d", &num2);
    }

    printf("\n");
    
    // Swap operation and result prints
    printf("Before swap: a = %d, b = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After swap: a = %d, b = %d\n", num1, num2);

}

void swap(int *a, int *b)
{
    int temp;

    temp = (*a); 
    (*a) = (*b);
    (*b) = temp; 
}