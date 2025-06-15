#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_string.h"

int main(void)
{
    FILE *in = fopen("busStop.txt", "r");
    if (in == NULL)
        printf("Error has occured when opening the file.\n");
    else
    {
        queue_t q; 
        initializeQ(&q); 

        char temp[20]; 
        while (fscanf(in, " %s", temp) != EOF)
            insert(&q, temp); 
        
        queue_t a = q; 

        printf("Waiting Passengers:\n"); 
        while (!isEmptyQ(&a))
           printf("%s\n", remove(&a)); 

        int pass; 
        printf("\nThe bus arrived to the bus stop!\n");
        printf("How many passengers getting on the bus? "); 
        scanf("%d", &pass); 

        printf("\nThe list of passengers getting on the bus:\n");

        for (int r = 0; r < pass; r++)
            printf("%s\n", remove(&q));

        printf("\nWaiting passengers:\n");
        while (!isEmptyQ(&q))
            printf("%s\n", remove(&q));
        printf("\n");
    } 
    return(0); 
}