#include <stdio.h>
#include <stdlib.h>
#include "queue_int.h"

int main(void)
{
    queue_t q; 
    initializeQ(&q); 
    
    int number; 
    do
    {
        printf("Enter a number (or negative to STOP) : ");
        scanf("%d", &number);

        if ((number >= 0) && (number % 2 != 0))     
            insert(&q, number); 
    } while (number >= 0);

    printf("Odd numbers were inserted into the queue\n\n"); 
    printf("Queue Content\n"); 
    printf("----------------------------------------\n");
    while (!isEmptyQ(&q))
        printf("%d  ", remove(&q)); 
    printf("\n"); 
    return(0);
}