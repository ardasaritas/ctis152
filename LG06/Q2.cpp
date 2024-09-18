#include <stdio.h>
#include <stdlib.h>

// Maximum number of customers in this file
#define MAX 20 

// Room Prices (Currency: TL)
#define STD 1000
#define TWN 2500
#define DBL 3500

typedef struct 
{
    int roomNumber;
    char roomType;
}room_t;

typedef struct 
{
    char customerName[20];
    int birthYear, day;
    double payment; 
    room_t roomInfo; 

} customer_t;

void readFromFile(FILE *in, customer_t *customers, int numOfCustomers);

void displayAll(customer_t *customers, int numOfCustomers);

double calculateTotalEarnings(customer_t *customers, int numOfCustomers);

int findCustomerMaxPayment(customer_t *customers, int numOfCustomers);

int main(void)
{
    FILE *in = fopen("customers.txt","r");

    if (in == NULL)
        printf("Error has occured when opening file.\n"); 
    else
    {
        int numOfCustomers = 0;
        double totalEarnings = 0.0;
        customer_t *customers; 
        customers = (customer_t *)malloc(sizeof(customer_t) * MAX); 

        do
        {
            printf("How many customers do you want to see (5-20)? "); 
            scanf("%d", &numOfCustomers);
        } while (numOfCustomers > 20 || numOfCustomers < 5);
        
        readFromFile(in, customers, numOfCustomers); 
        displayAll(customers, numOfCustomers); 
        
        totalEarnings = calculateTotalEarnings(customers, numOfCustomers);
        printf("\nTotal Earnings of the hotel: %0.2f TL\n\n", totalEarnings);   

        int index = findCustomerMaxPayment(customers, numOfCustomers);

        printf("The customer having the maximum payment for accomodation:\n");
        printf("%s with the price %0.2f TL\n\n", (customers + index)->customerName, (customers + index)->payment);
    }
}

void readFromFile(FILE *in, customer_t *customers, int numOfCustomers)
{
    int r = 0;
    while (fscanf(in, "%s %d %d %d %c", (customers + r)->customerName, &(customers + r)->birthYear, &(customers + r)->day, &(customers + r)->roomInfo.roomNumber, &(customers + r)->roomInfo.roomType) != EOF && (r < MAX))
        r++;

    for (int i = 0; i < r; i++)
        switch((customers + i)->roomInfo.roomType)
        {
            case 'S': 
            (customers+ i)->payment = (customers + i)->day * STD;
            break; 

            case 'T':
            (customers+ i)->payment = (customers + i)->day * TWN;
            break;

            case 'D': 
            (customers+ i)->payment = (customers + i)->day * DBL;
            break; 
        }    
}

void displayAll(customer_t *customers, int numOfCustomers)
{
    printf("Name              BYear   Day   Room Number   Type    Payment\n");
    printf("---------------   -----   ---   -----------   ----    -----------\n");

    for (int r = 0; r < numOfCustomers; r++)
        printf("%-15s   %-5d    %-2d      %-6d      %-2d     %-7.2f TL\n", (customers + r)->customerName, (customers + r)->birthYear, (customers + r)->day, (customers + r)->roomInfo.roomNumber, (customers + r)->roomInfo.roomType, (customers + r)->payment);
}

double calculateTotalEarnings(customer_t *customers, int numOfCustomers)
{
    double sum = 0.0;

    for (int r = 0; r < numOfCustomers; r++)
            sum += (customers + r)->payment;
    return(sum);
}

int findCustomerMaxPayment(customer_t *customers, int numOfCustomers)
{
    double max = customers->payment; 
    int index; 

    for (int r = 0; r < numOfCustomers; r++)
        if ((customers + r)->payment > max)
        {
            index = r;
            max = (customers + r)->payment;
        }
    return(index); 
}