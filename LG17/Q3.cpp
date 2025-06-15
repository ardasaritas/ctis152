#include <stdio.h>
#include <stdlib.h>
#include "stack_int.h"
#include "queue_int.h"

typedef struct 
{
    char command;
    int printer; 
}command_t;

void flushQ(queue_t *q);

int main(void)
{
    FILE *in = fopen("printingA.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the file.\n");
    else
    {
        stackk_t PC1; 
        initializeS(&PC1);
        push(&PC1, 60);
        push(&PC1, 50); 
        push(&PC1, 40);

        stackk_t PC2; 
        initializeS(&PC2);
        push(&PC2, 80);
        push(&PC2, 70);

        stackk_t PC3; 
        initializeS(&PC3);
        push(&PC3, 90);

        queue_t printer; 
        initializeQ(&printer); 

        queue_t printed;
        initializeQ(&printed);

        command_t data;

        while(fscanf(in," %c %d", &data.command, &data.printer) != EOF)
        {
            switch(data.command)
            {
                case 'S': 
                    switch(data.printer)
                    {
                        case 1: 
                            insert(&printer, pop(&PC1));
                            break;
                        case 2: 
                            insert(&printer, pop(&PC2));
                            break;
                        case 3: 
                            insert(&printer, pop(&PC3));
                            break;
                    }
                    break;
                case 'P':
                    insert(&printed, remove(&printer));
                    break;
            }
        }
        
        printf("Pending Jobs: ");
        flushQ(&printer);
        printf("Printed Jobs: ");
        flushQ(&printed);
    }
    fclose(in);
    return(0);
}

void flushQ(queue_t *q)
{
    while(!isEmptyQ(q))
    {
        int a = remove(q);
        printf("%d ",a);
    }
    printf("\n");
}