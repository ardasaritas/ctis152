/*****
Prints a num x num square's left hand side of the major diagonal
*****/
#include <stdio.h>

void printNStar(int num);

void printLines(int num); 

int main(void)
{
    int num;
    printf("Enter the number of lines: "); 
    scanf("%d", &num);

    printLines(num);
    printf("\n");
    return(0);
}

void printNStar(int num)
{
    if (num != 0)
    {
        printNStar(num - 1);
        printf("* ");
    }
}

void printLines(int num)
{
    if (num != 0)
    {
        printLines(num - 1);
        printNStar(num);
        printf("\n");
    }
}