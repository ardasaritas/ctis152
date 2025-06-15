#include <stdio.h>
#include <stdlib.h>
#include "stack_int.h"

int main(void)
{
    int num; 
    stackk_t S;
    initializeS(&S);

    do
    {
        printf("Enter a number: ");
        scanf("%d", &num); 
    } while (num < 10);
    
    printf("Digits of %d are ", num);
    while (num != 0)
    {
        push(&S, num % 10); 
        num /= 10;
    }
    while (!isEmptyS(&S))
        printf("%2d ", pop(&S));
    printf("\n");
    return(0);
}