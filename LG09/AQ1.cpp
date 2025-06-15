#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char customerName[30]; 
    char customerSurname[30]; 
    char shoppingDate[20]; 
    char nameOfStore[50];

} customer_t;

int search(char *string, char key);

int readFile(FILE *in, customer_t *customers); 

void display(customer_t *customers, int actSize); 

int main(void)
{
    FILE *in = fopen("customers.txt","r"); 

    if (in == NULL)
        printf("Error has occured when opening file.\n"); 
    else
    {
        customer_t *customers = (customer_t *)malloc(sizeof(customer_t) * 20); 
        if (customers == NULL)
            printf("No memory to allocate.\n"); 
        else
        {
            int actSize = readFile(in, customers); 
            fclose(in);
            display(customers, actSize); 
        }
    }
    return(0); 
}

int readFile(FILE *in, customer_t *customers)
{
    int count = 0;
    char dummy[2];  
    while(fscanf(in," %[^ ] %[^0-31] %[^ ] %[^\n]", (customers + count)->customerName, (customers + count)->customerSurname, (customers + count)->shoppingDate, (customers + count)->nameOfStore) != EOF)
        count++; 
    return(count);
}

void display(customer_t *customers, int actSize)
{
    printf("\nAWARD WINNING CUSTOMERS\n"); 
    printf("---------------------------------------------\n"); 

    // Checks whether the customer has one or two names, prints accordingly
    for (int r = 0; r < actSize; r++)
    {
        char dateHold[5]; 
        strncpy(dateHold, (customers + r)->shoppingDate, 5);
        printf("%s", dateHold); 
        
        if (strlen((customers + r)->customerName) + strlen((customers + r)->customerSurname) > 12)
        {
            char tmp[3];
            tmp[0] = (customers + r)->customerName[0];
            tmp[1] = '.';
            tmp[2] = '\0';
            strcpy((customers + r)->customerName, tmp);
            strcat((customers + r)->customerName, (customers + r)->customerSurname); 
            printf(" %-18s", (customers + r)->customerName); 
        }    
        else
        {
            strcat((customers + r)->customerName, " ");
            strcat((customers + r)->customerName, (customers + r)->customerSurname);
            printf(" %-18s", (customers + r)->customerName);
        }   
        printf("%s\n", (customers + r)->nameOfStore); 
    }    
    printf("\n");
}