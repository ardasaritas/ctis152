#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct 
{
    int pID; 
    double pPrice; 
    char pBrand[MAX];
    char pModel[MAX];
}phone_t;

void menu(int *choice); 

int readFromFile(FILE *in, phone_t *phones); 

void display(phone_t *phones, int size); 

void swap(double *a, double *b); 

void bubbleSortAsc(phone_t *phones, int size);

void bubbleSortDesc(phone_t *phones, int size);

void searchBrand(phone_t *phones, int size, char str[]); 

int main(void)
{
    FILE *in = fopen("phones.txt","r"); 

    if (in == NULL)
        printf("Error has occurred when opening the input file.\n"); 
    else
    {
        phone_t *phones; 
        phones = (phone_t *)malloc(sizeof(phone_t) * 20); // max defined in the question

        if (phones == NULL)
            printf("Something wrong with allocating memory.\n");
        else
        {
            int choice, ascOdesc, flag = 0;
            char key[20]; 

            int actsize = readFromFile(in, phones);

            menu(&choice); 
            while (choice != 4)
            {
                switch(choice)
                {
                    case 1: 
                    display(phones, actsize); 
                    break;
                    
                    case 2:
                    printf("Enter a brand to search: "); 
                    scanf(" %s", key); 
                    
                    for (int i = 0; i < actsize; i++)
                        if (strcmp(key,(phones + i)->pBrand) == 0)
                            flag++; 
                    
                    if (flag > 0)
                        searchBrand(phones, actsize, key);
                    else
                        printf("\nThere is no brand called %s.\n\n", key); 
                    break;

                    case 3: 
                    printf("Please select an order (1: Ascending, 2: Descending): ");
                    scanf("%d", &ascOdesc); 
                    switch(ascOdesc)
                    {
                        case 1: 
                        bubbleSortAsc(phones, actsize);
                        display(phones, actsize); 
                        break;

                        case 2:
                        bubbleSortDesc(phones, actsize); 
                        display(phones, actsize);
                    }
                }
            flag = 0;
            menu(&choice); 
            }
        }
    }
    return(0);
}

void menu(int *choice)
{
    printf("Menu\n"); 
    printf("********************************************\n");
    printf("1. Display Phone List\n2. Search for a brand\n");
    printf("3. Sort by price (Ascending/Descending) Order\n4. Exit\n\n");

    do
    {
        printf("Please enter your choice: ");
        scanf("%d", choice);
    } while (*choice > 4 || *choice < 1);
}

int readFromFile(FILE *in, phone_t *phones)
{
    int count = 0;
    while (fscanf(in, "%d %lf  %s %[^\n]", &(phones + count)->pID, &(phones + count)->pPrice, (phones + count)->pBrand, (phones + count)->pModel) != EOF && (count < 20))
    {
        (phones + count)->pModel[strlen((phones + count)->pModel) - 1] = '\0';
        count++;
    }     
    return(count);
}

void display(phone_t *phones, int size)
{
    printf("\nID    Brand          Model                           Price\n");
    printf("----------------------------------------------------------------\n");

    for (int r = 0; r < size; r++)
    {
        
        printf("%4d  %-10s     %-31s %8.2f TL \n", (phones + r)->pID, (phones + r)->pBrand, (phones + r)->pModel, (phones + r)->pPrice);
    }
    printf("\n");
}

void swap(double *a, double *b)
{
    double temp = *a; 
    *a = *b; 
    *b = temp;
}

void bubbleSortAsc(phone_t *phones, int size)
{
    int pass = 1, sorted; 

    do
    {
        sorted = 1;
        for (int r = 0; r < size - pass; r++)
            if ((phones + r)->pPrice > (phones + r + 1)->pPrice)
            {
                swap(&(phones + r)->pPrice, &(phones + r + 1)->pPrice);
                sorted = 0;
            }
    } while (!sorted);
}

void bubbleSortDesc(phone_t *phones, int size)
{
    int pass = 1, sorted; 

    do
    {
        sorted = 1;
        for (int r = 0; r < size - pass; r++)
            if ((phones + r)->pPrice < (phones + r + 1)->pPrice)
            {
                swap(&(phones + r)->pPrice, &(phones + r + 1)->pPrice);
                sorted = 0;
            }
    } while (!sorted);
}

void searchBrand(phone_t *phones, int size, char str[])
{
    printf("\nID    Brand          Model                           Price\n");
    printf("----------------------------------------------------------------\n");
    
    int count = 0; 

    for (int r = 0; r < size; r++)
        if (strcmp((phones + r)->pBrand, str) == 0)
        {
            printf("%4d  %-10s     %-31s %8.2f TL \n", (phones + r)->pID, (phones + r)->pBrand, (phones + r)->pModel, (phones + r)->pPrice);
            count++;
        }        
            
    printf("There are %d %s models.\n\n", count, str);
}