#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_struct.h"

#define SIZE 10

int hashCode(int supplyID); 

void initArray(node_t *hp[]);

void menu(int *choice);

node_t *searchSupplyID(node_t *hp, int supplyID); 

void insertSupply(node_t *hp[], LType supply);

void removeSupply(node_t *hp[], int supplyID);

void displayHashmap(node_t *hp[]); 

int main(void)
{
    node_t *hp[SIZE];
    initArray(hp);

    int choice; 
    LType temp;

    menu(&choice);
    while (choice != 4) // Exit if 4 
    {
        printf("\n");
        switch(choice)
        {
            case 1: 
                printf("Please enter a supply ID and price: ");
                scanf("%d %lf", &temp.supplyID, &temp.price);
                insertSupply(hp, temp);
            break;

            case 2: 
                printf("Please enter a supply ID to delete: ");
                scanf("%d", &temp.supplyID);
                removeSupply(hp, temp.supplyID);
            break;

            case 3:
                displayHashmap(hp);
            break; 
        }
        menu(&choice);
    }
    return(0);
}

int hashCode(int supplyID)
{
    return(supplyID % 10);
}

void initArray(node_t *hp[])
{
    for (int r = 0; r < SIZE; r++)
        hp[r] = NULL;
}

void menu(int *choice)
{
    printf("\n                MENU\n");
    printf("************************************\n");
    printf("1. Insert a supply into the hash table\n");
    printf("2. Remove a supply from the hash table\n");
    printf("3. Display the hash table\n");
    printf("4. Exit\n");
    printf("************************************\n\n");

    do
    {
        printf("Please enter your choice: ");
        scanf("%d", choice);
    } while (*choice > 4 || *choice < 1);
}

node_t *searchSupplyID(node_t *hp, int supplyID)
{
    while (hp != NULL && supplyID != hp->data.supplyID)
        hp = hp->next; 
    return(hp);
}

/*
void insertSupply(node_t *hp[], LType supply)
{
    int index = hashCode(supply.supplyID); 

    if (hp[index] == NULL) // list is empty
    {
        hp[index] = addBeginning(hp[index], supply);
        printf("Inserted supply\nSupply ID: %d\nSupply Price: %0.2f\n", supply.supplyID, supply.price);
    }
    else // if not empty
    {
        node_t *exist = searchSupplyID(hp[index], supply.supplyID);
        node_t *tp = hp[index]; // for traversal

        if (exist == NULL) // does not exist, addAfter last node
        {
            while(tp->next != NULL) // find last node
                tp = tp->next; 
            
            addAfter(tp, supply); // add as last node
            printf("Inserted supply\nSupply ID: %d\nSupply Price: %0.2f\n", supply.supplyID, supply.price);
        }
        else // exists, only update price
        {
            exist->data.price = supply.price;
            printf("Supply exists, price will be updated.\n");
        }
    }
}
*/

void insertSupply(node_t *hp[], LType supply)
{
    int index = hashCode(supply.supplyID);

    if (hp[index] == NULL) // list is empty
    {
        hp[index] = addBeginning(hp[index], supply); 
        printf("The supply is inserted.\n");
    }
    else // list is not empty,
    {
        node_t *exist = searchSupplyID(hp[index], supply.supplyID); // search the list
        node_t *tp = hp[index]; // to not distort the hp itself

        if (exist == NULL) // if does not exist 
        {
            while(tp->next != NULL)
                tp = tp->next; // traverse to last node

            //while (tp->next != NULL && supply.price > tp->next->data.price)
              //tp = tp->next; // sorted

            addAfter(tp, supply); // add 
            printf("The supply is inserted.\n");
        }
        else // it exists
        {
            exist->data.price = supply.price; // update only the price
            printf("The price is updated. ");
        }
    }
}

/*
void removeSupply(node_t *hp[], int supplyID)
{
    int index = hashCode(supplyID); 

    if (hp[index] == NULL) // list is empty
        printf("The supply does not exist.\n");
    else // list is not empty
    {
        if (hp[index]->data.supplyID == supplyID) // if first node
        {
            hp[index] = deleteBeginning(hp[index]); // job done
                printf("The supply %d is deleted.\n", supplyID);
        }
        else
        {
            node_t *exist = searchSupplyID(hp[index], supplyID);

            if (exist == NULL) // does not exist
                printf("The supply does not exist.\n");
            else // exists
            {
                node_t *tp = hp[index]; // to not mess with the hp
                while (tp->next != NULL && tp->next->data.supplyID != supplyID) // find the previous node
                    tp = tp->next; 
                deleteAfter(tp);
                printf("The supply %d is deleted.\n", supplyID);
            }
            
        }
    }
}
*/
void displayHashmap(node_t *hp[])
{
    for (int r = 0; r < SIZE; r++)
    {
        if (hp[r] == NULL) // empty
            printf("H[%d] has no elements\n", r);
        else
        {
            node_t *tp = hp[r]; // again not to mess with hp itself

            printf("H[%d]: ", r);
            while (tp != NULL)
            {
                printf("%d %0.2f -> ", tp->data.supplyID, tp->data.price);
                tp = tp->next;
            }
            printf("NULL\n");
        }
    }
}

void removeSupply(node_t *hp[], int supplyID)
{
    int index = hashCode(supplyID); 
    if (hp[index] == NULL)
        printf("List is empty");
    else // if not empty
    {
        node_t *exist = searchSupplyID(hp[index], supplyID); 

        if (exist == NULL) // does not exist
            printf("Item does not exist\n"); 
        else // exists
        {
            if (hp[index]->data.supplyID == supplyID) // beginning
                hp[index] = deleteBeginning(hp[index]); 
            else // if after beginning
            {
                node_t *tp = hp[index]; // not to distort the hp

                while (tp->next != NULL && tp->next->data.supplyID != supplyID) // find the previous node
                    tp = tp->next;

                deleteAfter(tp); 
            }

        }
    }
}