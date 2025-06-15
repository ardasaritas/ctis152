/******
Reads information about groceries from a file and displays them, 
also calculates total prices of each and has a search function to display
all of the selected product's details
*******/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id; 
    double unitPrice;
    int quantity; 
} grocery_t;

void readFromFile(FILE* in, grocery_t *groceries, int numOfItems);

void displayElement(grocery_t *groceries, int numOfItems, int key);

void displayMenu(grocery_t *groceries, int numOfItems);

int searchItem(grocery_t *groceries, int numOfItems, int key);

int main(void)
{
    FILE *in = fopen("grocery.txt","r"); 

    if (in == NULL)
        printf("Error has occurred when opening file.\n");
    else
    {
        int numOfItems, key; 

        fscanf(in,"%d", &numOfItems); 

        grocery_t *groceries; 
        groceries = (grocery_t *)malloc(sizeof(grocery_t) * numOfItems); 

        readFromFile(in, groceries, numOfItems); 
        displayMenu(groceries, numOfItems); 

        printf("\nEnter the id of an item: ");
        scanf("%d", &key); 

        int searchResult = searchItem(groceries, numOfItems, key);
        if (searchResult == -1)
            printf("Item not found.\n");
        else displayElement(groceries, numOfItems, searchResult);

        while (searchResult == -1)
        {
            printf("\n");
            displayMenu(groceries, numOfItems); 

            printf("\nEnter the id of an item: ");
            scanf("%d", &key); 

            searchResult = searchItem(groceries, numOfItems, key);
            if (searchResult == -1)
            printf("Item not found.\n");
            else displayElement(groceries, numOfItems, searchResult);
        }
        fclose(in);
        free(groceries);
    }
    return(0); 
}

void readFromFile(FILE* in, grocery_t *groceries, int numOfItems)
{
    int i = 0; 

    while ((fscanf(in, "%d %lf %d", &(groceries + i)->id, &(groceries + i)->unitPrice, &(groceries + i)->quantity) != EOF) && (i < numOfItems))
        i++; 
}

void displayElement(grocery_t *groceries, int numOfItems, int key)
{
    printf("\nID        :%7d\n", (groceries + key)->id);
    printf("Unit Price:%7.2f TL\n", (groceries + key)->unitPrice);
    printf("Quantity  :%7d \n", (groceries + key)->quantity);
    printf("Total     :%7.2f TL\n\n", ((groceries + key)->quantity * (groceries + key)->unitPrice));
}

void displayMenu(grocery_t *groceries, int numOfItems)
{
    printf("ID    Unit Price  Quantity  Total\n");
    printf("****  **********  ********  *********\n");
    
    for (int i = 0; i < numOfItems; i++)
        printf("%4d  %7.2f TL  %8d %7.2f TL\n", (groceries + i) -> id, (groceries + i) -> unitPrice, (groceries + i) -> quantity, (((groceries + i) -> quantity) * (groceries + i) -> unitPrice));
}
int searchItem(grocery_t *groceries, int numOfItems, int key)
{
    for (int i = 0; i < numOfItems; i++)
        if (key == (groceries + i)->id)
            return(i);
    return(-1);
}