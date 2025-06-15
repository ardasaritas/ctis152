#include <stdio.h>

typedef struct{
        char sportCode; 
        int playersCount;
        double averageScore;
} sport_t;

int main(void)
{
    printf("The Sport Information is:\n");
    
    sport_t tenis = {'T', 7, 8.10}; 
    sport_t *tenisptr = &tenis;

    printf("Sport Code: %c\n", tenisptr ->sportCode);
    printf("Number of Players: %d\n", tenis.playersCount); 
    printf("Average Score: %0.2f\n", (*tenisptr).averageScore);

    return (0);
}