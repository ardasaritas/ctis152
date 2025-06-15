#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char sportCode;
    int playersCount;
    double averageScore;
}sport_t;

int main(void)
{
    FILE *in = fopen("sports.txt","r");

    if (in == NULL)
        printf("Error has occured when opening file.\n");
    else
    {

        int count; 

        fscanf(in, "%d", &count);

        sport_t *sptr;
        sptr = (sport_t *)malloc(sizeof(sport_t) * count); 
        
        for (int i = 0; i < count; i++)
            fscanf(in," %c %d %lf", &((sptr + i) ->sportCode), &((sptr + i)->playersCount), &((sptr + i)->averageScore));

        printf("The Sports information is:\n");
        printf("**************************\n\n");

        for (int k = 0; k < count; k++)
        {
            printf("Sport Code: %c\n", (sptr + k) -> sportCode);
            printf("Number of Players: %d\n", sptr[k].playersCount);
            printf("Average Score: %0.2f\n\n", (*(sptr+k)).averageScore);
        }        
    fclose(in);
    }
    return (0);
}