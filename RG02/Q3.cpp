#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct 
{
    char brand[20];
    char model[20];
    int year; 
    double price; 
    char color[15];
}car_t;


void printRandomCars(car_t *cars, int count);

void readCars(FILE *bin, car_t *cars, int size);

int main(void)
{
    FILE *in = fopen("cars.bin","rb");

    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        fseek(in, 0, SEEK_END);
        int size = ftell(in) / sizeof(car_t);

        car_t *cars = (car_t *)malloc(sizeof(car_t) * size);

        rewind(in);
        readCars(in ,cars, size);
        fclose(in);

        srand(time(NULL));

        int count = rand() % size + 1;

        printf("Here is %d car's info\n\n", count);
        printRandomCars(cars, count);
        printf("\n");
        
        free(cars);
    }
    return(0);
}

void readCars(FILE *bin, car_t *cars, int size)
{
    if (fread(cars, sizeof(car_t), 1, bin))
        return readCars(bin, cars + 1, size);
}

void printRandomCars(car_t *cars, int count)
{
    if (count != 0)
    {
        printf("%s %s %d %0.2f %s\n", (cars + count)->brand, (cars + count)->model, (cars + count)->year, (cars + count)->price, (cars + count)->color);
        return printRandomCars(cars, count - 1);
    }
}