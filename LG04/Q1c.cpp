#include <stdio.h>

typedef struct{
        char sportCode;
        int playersCount;
        double averageScore;
} sport_t;

int main(void)
{
    sport_t sport; 
    
    printf("Enter sport code: ");
    scanf("%c", &(sport.sportCode));

    printf("Enter number of players: ");
    scanf("%d", &(sport.playersCount));

    printf("Average Score: ");
    scanf("%lf", &(sport.averageScore));
    
    
    printf("\nThe Sport Information is:\n");
    
    printf("Sport Code: %c\n", sport.sportCode);
    printf("Number of Players: %d\n", sport.playersCount); 
    printf("Average Score: %0.2f\n", sport.averageScore);

    return (0);
}