#include <stdio.h>
#include <stdlib.h>
#include "stack_int.h" // Initialized size of 3 for the ash
#include "queue_int.h" // Initialized size of 5 for the lot

// Washing lanes (stack of 3) is full with cars 1, 2, 3.

// A car arrives (denoted 'A') passes through the lot (queue of 5) 
// enters the lanes if there is an empty one. If the lot is full, they 
// won't be allowed to enter

// When a car is washed and ready to depart (denoted 'D') as it is a stack, 
// first other cars are removed and inserted back after the departed one exits.

//After each operation, stack and queue is displayed.

// Makes the appropriate operation inside stack and queue, using a file.
void carWash(FILE *in, queue_t *lot, stackk_t *wash);

void initializeLanes(stackk_t *wash);

int main(void)
{
    FILE *in = fopen("carWash.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        queue_t lot;
        initializeQ(&lot); 

        stackk_t wash; 
        initializeS(&wash);

        initializeLanes(&wash);
        carWash(in, &lot, &wash);
    }
   fclose(in);
   return(0);
}

void initializeLanes(stackk_t *wash)
{
    push(wash, 1);
    push(wash, 2);
    push(wash, 3);
}

void carWash(FILE *in, queue_t *lot, stackk_t *wash)
{
    char command;
    int id;
    
    while(fscanf(in, " %c %d", &command, &id) != EOF)
    {
        switch(command)
        {
            case 'A': // Arrive at parking lot
                if (!isFullQ(lot)) // If there is an empty space
                {
                    insert(lot, id); // pull up in the lot

                    if (!isFullS(wash)) // if washing available
                        push(wash, remove(lot)); // go from lot to wash
                }
            break;

            case 'D': // Intention of departing from washing lane
                stackk_t temp; 
                initializeS(&temp);
                int data; 
                
                // Empty the washing lanes, push cars which are not departing to a stack
                while (!isEmptyS(wash)) 
                {
                    data = pop(wash);
                    if (data != id)
                        push(&temp, data);
                }

                // Push back all 
                while(!isEmptyS(&temp))
                    push(wash, pop(&temp));
                
                // Since one empty space will be guaranteed, get a car to washing from lot
                push(wash, remove(lot));
            break;
        }
        displayStack(*wash); // display washing lanes after each operation
        displayQueue(*lot);  // display lot after each operation
    }
}