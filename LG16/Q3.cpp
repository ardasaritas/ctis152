#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_struct.h"

void calculatePayment(car_t *cust); 

void fillQueue(FILE *in, queue_t *q);

void dailyReport(queue_t q); 

int main(void)
{
    FILE *in = fopen("customers.txt","r"); 

    if (in == NULL)
        printf("Error has occured when opening the input file.\n"); 
    else
    {
        queue_t q;
        initializeQ(&q); 

        fillQueue(in, &q); 
        dailyReport(q);
    }
    fclose(in); 
    return(0);
}

void calculatePayment(car_t *cust)
{
    double price;
    switch(cust->fuelType)
    {
        case 'D': 
            price = 42.83;
            break;
        case 'F':
            price = 44.23;
            break;
    }
    cust->payment = cust->liter * price; 
}

void fillQueue(FILE *in, queue_t *q)
{
    car_t temp; 
    while(fscanf(in, " %s %c %lf", temp.plate, &temp.fuelType, &temp.liter) != EOF)
    {
        calculatePayment(&temp); 
        insert(q, temp); 
    }
}

void dailyReport(queue_t q)
{
    printf("\nPlate      Fuel Type   Liter  Payment\n");
    printf("*********  *********   *****  **********\n"); 
    double sumLit = 0.0, sumPay = 0.0;
    car_t temp;
    while (!isEmptyQ(&q))
    {
        temp = remove(&q);
        printf("%-9s      %c       %5.2f  %7.2f TL\n", temp.plate, temp.fuelType, temp.liter, temp.payment); 
        sumLit += temp.liter;
        sumPay += temp.payment;
    }
    printf("\nTotal Liter Sold: %5.2f\n", sumLit); 
    printf("Total payment   : %8.2f TL\n\n", sumPay); 
}