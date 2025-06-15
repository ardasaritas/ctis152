#include <stdio.h>
#include <stdlib.h>
#include "queue_struct.h"
#include "stack_struct.h"

void displayQueue(queue_t q);

void displayStack(stackk_t s);

int main(void)
{
    FILE *in = fopen("items.txt","r"); 
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        stackk_t s;
        initializeS(&s);

        queue_t q;
        initializeQ(&q);

        SType tempStack;
        QType tempQueue; 

        while (fscanf(in, "%d %lf %d", &tempStack.id, &tempStack.price, &tempStack.stock) != EOF)
        {
            if (tempStack.stock < 100)
            {
                tempQueue.id = tempStack.id;
                tempQueue.price = tempStack.price;
                tempQueue.stock = tempStack.stock;
                insert(&q, tempQueue);
            }
            else    
                push(&s, tempStack);
        }

        displayQueue(q);
        displayStack(s);

        while(!isEmptyQ(&q))
        {
            int purchase;
            tempQueue = remove(&q);
            printf("Enter the purchase amount for item %d (min %d): ", tempQueue.id, 100 - tempQueue.stock);
            scanf("%d", &purchase);
            while (purchase < 100 - tempQueue.stock)
            {
                printf("Wrong Input\nEnter the purchase amount for item %d (min %d): ", tempQueue.id, 100 - tempQueue.stock);
                scanf("%d", &purchase);
            }
            tempStack.id = tempQueue.id;
            tempStack.price = tempQueue.price;
            tempStack.stock = tempQueue.stock;
            push(&s, tempStack);
        }
        printf("\n");
        displayStack(s);
    }
    fclose(in);
    return(0);
}

void displayQueue(queue_t q)
{
    printf("Queue Content:\n");
    while(!isEmptyQ(&q))
    {
        QType a = remove(&q);
        printf("%d %0.2f %d\n",a.id, a.price, a.stock);
    }
    printf("\n");
}

void displayStack(stackk_t s)
{
    printf("Stack Content:\n");
    while(!isEmptyS(&s))
    {
        SType a = pop(&s); 
        printf("%d %0.2f %d\n", a.id, a.price, a.stock);
    }
    printf("\n");
}