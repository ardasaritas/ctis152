#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct 
{
    char brand[20];
    char model[20];
    int year; 
    double price; 
    char color[15];
}car_t;

int main(void)
{
    FILE *inp = fopen("cars.bin","rb");

    if (inp == NULL)
        printf("Error opening file.\n");
    else
    {
        car_t n;
        
        rewind(inp);
        while (fread(&n, sizeof(car_t), 1, inp) == 1)
            printf("%s %s %d %0.2f %s\n", n.brand, n.model, n.year, n.price, n.color);
    }
    return(0);
}