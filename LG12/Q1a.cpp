/*****
Print the digits of an integer in reverse.
*****/
#include <stdio.h>

void printDigits(int num)
{
    if (num < 10)
        printf("%d ", num % 10); 
    else
    {
        printf("%d ", num % 10);
        printDigits(num / 10);
    }
}

int main(void)
{
    int num;
    
    printf("Enter a number to be reversed: "); 
    scanf("%d", &num); 

    printDigits(num); 
    printf("\n");
    return(0);
}