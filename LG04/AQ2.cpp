/*****
Reads information about swimmers and displays the ones who do meet the criterias 
******/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
   char sName[20];
   char sSurName[20];
   double time; 
   char medalInfo; 
}swimmer_t;
// Reads the file into a swimmer_t type array
void readFile(FILE *in, swimmer_t *swimmers, int numOfSwimmers); 

// Displays swimmers' information and checks criterias
void display(swimmer_t *swimmers, int numOfSwimmers); 

int main(void)
{
    FILE *in = fopen("swimmers.txt","r");

    if (in == NULL)
        printf("Error has occured when opening file.\n");
    else
    {
        int count; 
        fscanf(in, "%d", &count);
        
        swimmer_t *swimmers; 
        swimmers = (swimmer_t *)malloc(sizeof(swimmer_t) * count);

        readFile(in, swimmers, count); 
        display(swimmers, count); 

        fclose(in);
        free(swimmers);
    }
    return(0);
}

void readFile(FILE *in, swimmer_t *swimmers, int numOfSwimmers)
{
    int i = 0;
    while((fscanf(in,"%s %s %lf %c", (swimmers + i)->sName, (swimmers + i)->sSurName, &((swimmers + i)->time), &((swimmers + i)->medalInfo)) != EOF) && (i < numOfSwimmers))
        i++; 
}

void display(swimmer_t *swimmers, int numOfSwimmers)
{
    printf("Swimmer Name    Surname    Time to Complete the Lane   Medal Info\n");
    printf("************   *********   *************************   **********\n");
    
    int i, count = 0;
    for (i = 0; i < numOfSwimmers; i++)
        if ((swimmers + i)->medalInfo == 'Y' && (swimmers + i)->time < 160)
        {
            printf("%-12s   %-9s   %3.0f seconds %1.0f miliseconds        %c\n", (swimmers + i)->sName, (swimmers + i)->sSurName, (swimmers + i)->time, fmod((swimmers + i)->time, 10), (swimmers + i)->medalInfo);
            count++;      
        }
        
    printf("\nThere are %d swimmers with medals for swimming race.\n", count); 
}