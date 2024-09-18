/*****
Print the digits of an integer in ordinary order.
*****/
#include <stdio.h>

void printDigits(int num)
{
    if (num < 10)
        printf("%d ", num % 10); 
    else
    {
        printDigits(num / 10);
        printf("%d ", num % 10);
    }
}

int main(void)
{
    int num;
    
    printf("Enter a number for displaying its digits: "); 
    scanf("%d", &num); 

    printDigits(num); 
    printf("\n");
    return(0);
}