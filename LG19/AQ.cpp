#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_struct3.h"

void displayList(node_t *hp);

void menu(int *choice);

node_t *searchID(node_t *hp, int item);

void addToEnd(node_t *hp, LType veggy);

node_t *createList(FILE *in, node_t *hp);

node_t *updateList(node_t *hp);

void writeList(node_t *hp, char *fileName);

void freeList(node_t *hp); 

int main(void)
{
    char fileName[20];
    printf("Enter the text file name: ");
    scanf(" %s", fileName);

    FILE *in;
    in = fopen(fileName, "r");

    while (in == NULL)
    {
        printf("Enter the text file name: ");
        scanf(" %s", fileName);
        in = fopen(fileName, "r");
    }
    
    node_t *hp = NULL;
    hp = createList(in, hp);

    displayList(hp);

    int choice;
    LType newNode;
    node_t *val;

    menu(&choice);
    while (choice != 3)
    {
        switch(choice)
        {
            case 1:
                printf("\nEnter vegetable ID: ");
                scanf("%d", &newNode.ID);
                val = searchID(hp, newNode.ID);
                if (val != NULL)
                    printf("ID %d is already in the list.\n", newNode.ID);
                else
                {
                    printf("Enter vegetable name: ");
                    scanf(" %s", newNode.name);
                    printf("Enter vegetable price: ");
                    scanf("%lf", &newNode.price);

                    addToEnd(hp, newNode);
                }
            break;

            case 2:
                hp = updateList(hp);
            break;
        }
        displayList(hp);
        menu(&choice);
    }
    writeList(hp, fileName);
    printf("The linked list is written in a binary file named \"%s\" \nGoodbye\n", fileName);
    fclose(in);
    freeList(hp);
    return(0);
}

void displayList(node_t *hp)
{
    printf("\nID     Name         Price\n");
    printf("-------------------------\n");
    while (hp != NULL)
    {
        printf("%-7d%-13s%5.2f\n", hp->data.ID, hp->data.name, hp->data.price);
        hp = hp->next;
    }
}

void menu(int *choice)
{
    printf("\nMENU\n");
    printf("----------------\n");
    printf("1. Add Record\n");
    printf("2. Update Record\n");
    printf("3. Exit\n");
    printf("----------------\n");
    printf("Enter your choice: ");
    scanf("%d", choice);

    while (*choice > 3 || *choice < 1)
    {
        printf("Please enter a valid choice: ");
        scanf("%d", choice);
    }
}

node_t *searchID(node_t *hp, int item)
{
    while (hp != NULL && hp->data.ID != item)
        hp = hp->next;
    return(hp);
}

void addToEnd(node_t *hp, LType veggy)
{
    while (hp->next != NULL)
        hp = hp->next; 
    
    addAfter(hp, veggy);
}

node_t *createList(FILE *in, node_t *hp)
{
    LType temp;  
    fscanf(in,"%d %s %lf", &temp.ID, temp.name, &temp.price);
    hp = addBeginning(hp, temp);
    node_t *tp = hp;

    while (fscanf(in,"%d %s %lf", &temp.ID, temp.name, &temp.price) != EOF)
    {
        addAfter(tp, temp);
        tp = tp->next;
    }

    return(hp);
}

node_t *updateList(node_t *hp)
{
    LType newNode;
    node_t *val;

    printf("\nEnter vegetable ID: ");
    scanf("%d", &newNode.ID);
                
    val = searchID(hp, newNode.ID);
    while (val == NULL)
    {
        printf("Please enter an ID on the list: ");
        scanf("%d", &newNode.ID);
        val = searchID(hp, newNode.ID);
    }
    printf("\nEntry : %-7d%-13s%5.2f\n\n", val->data.ID, val->data.name, val->data.price);
    int updChoice;
    printf("Update (1 : ID, 2 : Name, 3 : Price): ");
    scanf("%d", &updChoice);
    node_t *temp;
    switch(updChoice)
    {
        case 1:
            printf("Enter the new ID: ");
            scanf("%d", &newNode.ID);
            
            val->data.ID = newNode.ID;

            temp = searchID(hp, newNode.ID);
            while (temp != NULL)
            {
                printf("ID %d is already in the list.\n", newNode.ID);
                printf("Please enter a unique ID: ");
                scanf("%d", &newNode.ID);
                temp = searchID(hp, newNode.ID);
            }
            val->data.ID = newNode.ID;
        break;
                    
        case 2: 
            printf("Enter the new name: ");
            scanf(" %s", val->data.name);
        break;

            case 3:
            printf("Enter the new price: ");
            scanf("%lf", &val->data.price);
        break;
    }
    return(hp);
}

void writeList(node_t *hp, char *fileName)
{
    while (fileName[strlen(fileName) - 1] != '.')
        fileName[strlen(fileName) - 1] = '\0';

    strcat(fileName, "bin");
    FILE *binOut = fopen(fileName, "wb");
    
    int size = 1;
    node_t *tp = hp;
    while (tp->next != NULL)
    {
        size++;
        tp = tp->next; 
    }

    LType *Ap = (LType *)malloc(sizeof(LType) * size);

    for (int r = 0; r < size; r++)
    {
        Ap[r] = hp->data;
        hp = hp->next;
    }

    fwrite(Ap, sizeof(LType), size, binOut);

    free(Ap);
    fclose(binOut);
}

void freeList(node_t *hp)
{
    while (hp != NULL)
        hp = deleteBeginning(hp);
}