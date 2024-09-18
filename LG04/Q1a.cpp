#include <stdio.h>

typedef struct{
        char sportCode;
        int playersCount;
        double averageScore;
} sport_t;

int main(void)
{
    printf("The Sport Information is:\n");
    
    sport_t football = {'F', 11, 8.50}; 

    printf("Sport Code: %c\n", football.sportCode);
    printf("Number of Players: %d\n", football.playersCount); 
    printf("Average Score: %0.2f\n", football.averageScore);

    return (0);
}