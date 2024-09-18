#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_struct2.h"

void getFlights(FILE *in, queue_t *q, int maxPass);

void displayFlights(queue_t q);

QType findMinWaste(queue_t q, int maxPass);

int main(void)
{
    FILE *in = fopen("flights.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        queue_t q;
        initializeQ(&q); 

        int maxPassenger, numFlight; 
        printf("Enter the maximum passenger count per flight: ");
        scanf("%d", &maxPassenger); 

        getFlights(in, &q, maxPassenger); 
        fclose(in);
        printf("There are %d flights.\n", q.counter);
        displayFlights(q);  
        
        truck_t minWasteFlight = findMinWaste(q, maxPassenger); 
        printf("The flight %s will have the minimum wasted capacity with %d passengers.\n\n", minWasteFlight.flightNo, minWasteFlight.seats);
        

        printf("How many flights do you need? ");
        scanf("%d", &numFlight); 

        printf("\nThe flights in the queued order for you are:\n");

        for (int r = 0; r < numFlight; r++)
        {
            truck_t temp = remove(&q); 
            printf("%d. flight: %s %d\n", r + 1, temp.flightNo, temp.seats);
        }

        printf("\nRemaining flights: %d\n", q.counter);
        displayFlights(q);
    }
    return(0);
}

void getFlights(FILE *in, queue_t *q, int maxPass)
{
    truck_t inserted; 
    while(fscanf(in, "%s %d", inserted.flightNo, &inserted.seats) != EOF)
        if (inserted.seats >= maxPass)
            insert(q, inserted); 
}

void displayFlights(queue_t q)
{
    printf("***********************\n");
    while(!isEmptyQ(&q))
    {
        truck_t temp = remove(&q);
        printf("%s %d\n", temp.flightNo, temp.seats);
    }
    printf("\n");
}

QType findMinWaste(queue_t q, int maxPass)
{
    truck_t temp = remove(&q), minWaste;
    int min = temp.seats - maxPass; 

    while(!isEmptyQ(&q))
    {
       temp = remove(&q);
       if (temp.seats - maxPass < min)
        {
            min = temp.seats - maxPass;
            minWaste = temp;
        }
    }
    return minWaste;
}