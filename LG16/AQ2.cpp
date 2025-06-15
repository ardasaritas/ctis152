#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue_struct3.h"

#define PACKAGEPERPEOPLE 0.5

int removeFromQueue(queue_t *q, char *nameofHolder, QType *temp);

void fillQueue(FILE *in, queue_t *q);

void displayQueue(queue_t q);

int main(void)
{
    FILE *in = fopen("village.txt","r"); 
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        queue_t q;
        initializeQ(&q);

        fillQueue(in, &q);
        displayQueue(q);
        
        char yn;
        printf("Do we have damaged package? ( Y / N ) : ");
        scanf(" %c", &yn); 

        while (yn != 'N' && yn != 'n')
        {
            switch(yn)
            {
            case 'Y':
            case 'y': 
                char nameHouseHold[40]; 
                printf("\nEnter the household: ");
                scanf(" %[^\n]", nameHouseHold); 
                QType temp; 
                if(removeFromQueue(&q, nameHouseHold, &temp))
                {
                    int damPack;
                    printf("\nHow many packages was damaged? ");
                    scanf("%d", &damPack);
                    temp.noOfPackage = damPack; 
                    insert(&q, temp);
                    displayQueue(q); 
                }
                else 
                {
                    printf("There is no household with the specified name.\n");
                    displayQueue(q); 
                }
               
                break; 
            }
            printf("Do we have damaged package? ( Y / N ) : ");
            scanf(" %c", &yn);
        }
        if (yn == 'N' || yn == 'n')
            printf("\nThank you for help.\n\n");
    }
    fclose(in);
    return(0);
}

int removeFromQueue(queue_t *q, char *nameofHolder, QType *temp)
{
    queue_t temp2 = *q;
    int index = -1;
    for (int r = 0; r < q->counter; r++)
    {
        QType a = remove(&temp2);
        if (strcmp(a.houseHolder, nameofHolder) == 0)
            index = r;
    }
    
    if (index == -1)
        return 0;
    
    *temp = q->data[index];

    while (q->rear != index)
    {
        q->data[index] = q->data[index + 1]; 
        index++;
    }
    q->rear--;
    q->counter--;
    return 1;
}
void fillQueue(FILE *in, queue_t *q)
{
    QType temp; 
    while(fscanf(in," %[^':']:%d %d", temp.houseHolder, &temp.distance, &temp.noOfPeople) != EOF)
    {
        if(temp.noOfPeople == 1)
            temp.noOfPackage = 1;
        else
            temp.noOfPackage = roundf(temp.noOfPeople * PACKAGEPERPEOPLE);
        insert(q ,temp);
    }
}

void displayQueue(queue_t q)
{
    printf("\nThe list of people:\n\n");
    printf("House Holder       Distance        # of People        # of Package \n");
    printf("***********************************************************************\n");
    while (!isEmptyQ(&q))
    {
        QType temp = remove(&q);
        printf("%-17s     %2d               %d                   %d\n",temp.houseHolder, temp.distance, temp.noOfPeople, temp.noOfPackage);
    }
    printf("\nAll of the packages were distributed.\n");
}