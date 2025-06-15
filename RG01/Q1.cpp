#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RATE1 0.5
#define RATE2 0.4
#define RATE3 0.3

typedef struct 
{
    int id; 
    double tot_success;
}distributor_t;

typedef struct 
{
    int first_c,
        second_c,
        third_c;
}sales_t;

int readFromFile(FILE *in, distributor_t *distributors, sales_t *sales); 

void display(distributor_t *distributors, sales_t *sales, int size);

void calculateTotalSuccess(distributor_t *distributors, sales_t *sales, int size);

double calculateTotalSuccessAvg(distributor_t *distributors, int size); 

int main(void)
{
    FILE *in = fopen("distributor.txt","r");

    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        int flag;
        fscanf(in,"%d", &flag);

        distributor_t *distributors; 
        distributors = (distributor_t *)malloc(sizeof(distributor_t) * flag);

        sales_t *sales;
        sales = (sales_t *)malloc(sizeof(sales_t) * flag);

        if (distributors == NULL || sales == NULL)
            printf("Check the memory allocation.\n");
        else
        {
            int actsize = readFromFile(in, distributors, sales);
            calculateTotalSuccess(distributors, sales, actsize);
            display(distributors, sales, actsize);

            double avg = calculateTotalSuccessAvg(distributors, actsize); 

            printf("\nTotal Success Average is: %f\n", avg);  
            int count = 0;
            for (int r = 0; r < actsize; r++)
                if ((distributors + r)->tot_success < avg)
                {
                    printf("Distributor %d will get a warning with a total success amount of %0.2f\n", (distributors + r)->id, (distributors + r)->tot_success);
                    count++;
                }    
                    
            printf("Total number of warned distributor(s) is(are) %d\n", count);
        }
    }
    return(0);
}

int readFromFile(FILE *in, distributor_t *distributors, sales_t *sales)
{
    int count = 0; 
    while (fscanf(in,"%d %d %d %d", &(distributors + count)->id, &(sales + count)->first_c, &(sales + count)->second_c, &(sales + count)->third_c) != EOF)
        count++;
    return(count);
}

void display(distributor_t *distributors, sales_t *sales, int size)
{
    for (int r = 0; r < size; r++)
    {
        printf("Distributor ID: %d\n", (distributors + r)->id);
        printf("Distributor First Class Sale Amount: %d\n", (sales + r)->first_c);
        printf("Distributor Second Class Sale Amount: %d\n", (sales + r)->second_c);
        printf("Distributor Third Class Sale Amount: %d\n", (sales + r)->third_c);
        printf("Distributor Total Success: %0.2f\n\n", (distributors + r)->tot_success);
    }    
}

void calculateTotalSuccess(distributor_t *distributors, sales_t *sales, int size)
{
    for (int r = 0; r < size; r++)
        (distributors + r)->tot_success = (sales + r)->first_c * RATE1+ (sales + r)->second_c * RATE2+ (sales + r)->third_c * RATE3;
}

double calculateTotalSuccessAvg(distributor_t *distributors, int size)
{
    double sum = 0; 
    for (int r = 0; r < size; r++)
        sum += (distributors + r)->tot_success;
    return(sum / size);
}