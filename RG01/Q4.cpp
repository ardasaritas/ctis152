#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int id; 
    char cur[3]; 
    int balance; 
    char type[10];
}customer_t;

void readFromFile(FILE *in, customer_t *customers, int size); 

void displayCustomerTypes(customer_t *customers, int size);

int main(void)
{
    FILE *in = fopen("customers.txt","r");

    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        int flag;
        fscanf(in,"%d",&flag);

        customer_t *customers;
        customers = (customer_t *)malloc(sizeof(customer_t) * flag); 

        if (customers == NULL)
            printf("Check memory allocation.\n");
        else
        {
            readFromFile(in, customers, flag); 
            displayCustomerTypes(customers, flag);
        }
    }
    return(0);
}

void readFromFile(FILE *in, customer_t *customers, int size)
{
    int r = 0; 
    while (fscanf(in,"%d %s %d", &(customers +r)->id, (customers + r)->cur, &(customers + r)->balance) != EOF && (r <= size))
        r++;

    for (int i = 0; i < size; i++)
    {
        if ((customers + i)->balance > 1000000 && (strcmp((customers + i)->cur, "TL") == 0))
            strcpy((customers + i)->type, "GOLD");
        else if ((customers + i)->balance > 100000 && (strcmp((customers + i)->cur, "TL") == 0))     
            strcpy((customers + i)->type, "PREMIUM" );
        else 
            strcpy((customers + i)->type, "BRONZE");

        if (strcmp((customers + i)->cur, "USD") == 0)
            strcpy((customers + i)->type, "DOLLAR");
        else if (strcmp((customers + i)->cur, "EUR") == 0)
            strcpy((customers + i)->type, "EURO");
    }    
}

void displayCustomerTypes(customer_t *customers, int size)
{
    printf("CUSTOMER ID   CUSTOMER TYPE\n");
    printf("---------------------------\n");

    for (int r = 0; r < size; r++)
        printf("%d             %11s\n", (customers + r)->id, (customers + r)->type);
}
