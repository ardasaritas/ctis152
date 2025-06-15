#include <stdio.h>
#include <stdlib.h>

// There are 20 radio frequencies in this file
#define MAX 20

typedef struct 
{
    double frequency; 
    char name[20]; 
    int numOfHits;    
}radio_t;

void read(FILE *in, radio_t *radios, int numOfRadios);

void display(radio_t *radios, int numOfRadios); 

int findMaxHits(radio_t *radios, int numOfRadios);

int findRadio(radio_t *radios, int numOfRadios, double keyFrequency);

int main(void)
{
    FILE *in = fopen("radio.txt","r"); 

    if (in == NULL)
        printf("Error has occured when opening file.\n");
    else
    {
        int numOfRadios = 0, indexOfMax, key; 
        double keyFrequency;
        radio_t *radios;
        radios = (radio_t *)malloc(sizeof(radio_t) * MAX); 
        do
        {
             printf("How many radios do you want to see? ");
            scanf("%d", &numOfRadios); 
        }while(numOfRadios > 20 || numOfRadios < 0);
       

        read(in, radios, numOfRadios); 
        display(radios, numOfRadios); 
        
        indexOfMax = findMaxHits(radios, numOfRadios); 

        printf("The radio <%s> has the maximum hits\n", (radios + indexOfMax)->name);
        printf("Frequency: %0.1f\nHits     : %d\n\n", (radios + indexOfMax)->frequency, (radios + indexOfMax)->numOfHits);
        
        printf("Enter a radio frequency to search: "); 
        scanf("%lf", &keyFrequency);

        key = findRadio(radios, numOfRadios, keyFrequency);

        if (key == -1)
            printf("\nSorry! There is no radio on the given frequency.\n"); 
        else 
            printf("\nRadio <%s> is on the %0.1f frequency.\n", (radios + key)->name, (radios + key)->frequency);
        
        fclose(in);
        free(radios);
    }
    return(0);
}

void read(FILE *in, radio_t *radios, int numOfRadios)
{
    int i = 0; 
    while(fscanf(in, "%lf %s %d", &((radios + i)->frequency), (radios + i)->name, &((radios +i)->numOfHits)) != EOF && (i < MAX))
        i++;
}

void display(radio_t *radios, int numOfRadios)
{
    printf("Frequency  Name         #ofHits\n");
    printf("*********  ************ *******\n");

    for (int r = 0; r < numOfRadios; r++)
        printf("%9.1f  %-12s %7d\n", (radios + r)->frequency, (radios + r)->name, (radios + r)->numOfHits);
    printf("\n");
}

int findMaxHits(radio_t *radios, int numOfRadios)
{
    int max = radios->numOfHits, index;

    for (int r = 0; r  < numOfRadios; r++)
        if ((radios + r)->numOfHits > max)
            index = r;  

    return(index);
}

int findRadio(radio_t *radios, int numOfRadios, double keyFrequency)
{
    int index = -1; 

    for(int r = 0; r < numOfRadios; r++)
        if((radios + r)->frequency == keyFrequency)
            index = r;
    
    if (index != -1)
        return (index);
    else
        return (-1);
}