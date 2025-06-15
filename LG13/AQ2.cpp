#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countRec(int numOfChocolates, int reqWrappers);

int main(void)
{
    int money, unitPrice, reqWrappers; 

    printf("How much money do you have? ");
    scanf("%d", &money); 

    printf("Enter the unit price for chocolate: ");
    scanf("%d", &unitPrice);

    printf("Enter the required number of wrappers for extra chocolate: ");
    scanf("%d", &reqWrappers);

    printf("\nYou can buy %d chocolates\n\n", money / unitPrice);

    printf("\nFinal count of chocolates: %d\n", countRec(money / unitPrice, reqWrappers));
    return(0);
}

int countRec(int numOfChocolates, int reqWrappers)
{
    while (numOfChocolates >= reqWrappers)
    {
        printf("You can return %d wrappers back and get %d more chocolate.\n", numOfChocolates, numOfChocolates / reqWrappers);
        
        if (numOfChocolates % reqWrappers == 0)
           return numOfChocolates + countRec(numOfChocolates / reqWrappers, reqWrappers);
        else    
            return numOfChocolates - numOfChocolates % reqWrappers + countRec(numOfChocolates / reqWrappers + numOfChocolates % reqWrappers, reqWrappers);
    }
    return 1;
}