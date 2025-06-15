#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_struct.h"

void fillQueue(FILE *in, queue_t *q);

void displayQueue(queue_t q);

void shopOfTheDay(queue_t q);

//int removeShop(queue_t *q, char *nameOfShop);
int removeAShop(queue_t * shops, char * shopName);

int main(void)
{
    FILE *in = fopen("shops.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        queue_t q; 
        initializeQ(&q); 

        fillQueue(in, &q);
        displayQueue(q);
        shopOfTheDay(q); 

        char shopName[25];
        printf("Enter a shop name to delete: ");
        scanf(" %s", shopName);

        if(removeAShop(&q, shopName))
            printf("The shop was deleted from the queue\n");
        else
            printf("Shop not on the list\n");

        displayQueue(q);
    }
    fclose(in);
    return(0); 
}

void fillQueue(FILE *in, queue_t *q)
{
    QType temp;
    while(fscanf(in," %s %lf", temp.shopName, &temp.sale) != EOF)
        insert(q, temp);
}

void displayQueue(queue_t q)
{
    printf("\nThe list of all shops:\n");
    printf("Shop Name         Sale Amount\n");
    printf("*****************************\n");
    while (!isEmptyQ(&q))
    {
        QType temp = remove(&q); 
        printf("%-18s   %8.2f\n", temp.shopName, temp.sale);
    }
}

void shopOfTheDay(queue_t q)
{
   
    QType temp;
    QType max = remove(&q);

    while(!isEmptyQ(&q))
    {
        temp = remove(&q);
        if(temp.sale > max.sale)
            max = temp;
    }
    
    printf("\nThe Shop of the day\n");
    printf("*****************************\n");
    printf("%-18s   %8.2f\n\n", max.shopName, max.sale);
}

/*int removeShop(queue_t *q, char *nameOfShop)
{
    queue_t temp2 = *q;
    int index = -1;
    for (int r = 0; r < q->counter; r++)
    {
        QType a = remove(&temp2);
        if (strcmp(a.shopName, nameOfShop) == 0)
            index = r;
    }

    if (index == -1)
        return 0;

    while (q->rear != index)
    {
        q->data[index] = q->data[index + 1]; 
        index++;
    }
    q->rear--;
    q->counter--;

    return 1;
}
*/

int removeAShop(queue_t * shops, char * shopName)
{
	int n = shops->counter;
	int found = 0;

	shop_t temp;

	for(int i = 0; i < n; i++)
	{
		temp = remove(shops);
		if (strcmp(temp.shopName, shopName) != 0)
			insert(shops, temp);
		else
			found = 1;
	}
	return found;
}