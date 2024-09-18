#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char type; 
    int year; 
    char color; 
    double km; 
    double price;
}car_t;

char typeStr[3][10] = {"Mercedes", "Peugeot", "Honda"}; 
char colorStr[3][10] = {"White", "Red", "Blue"}; 

void menu(int *choice); 

void readFile(FILE *in, car_t *cars, int flag); 

void displayType(car_t *cars, int size); 

void displayModel(car_t *cars, int size); 

void displayColor(car_t *cars, int size); 

void displayKM(car_t *cars, int size); 

void displayPrice(car_t *cars, int size);

void convertoUpper(char *ch);

int main(void)
{
    FILE *in = fopen("cars.txt","r"); 

    if (in == NULL)
        printf("Error has occured when opening the input file.\n"); 
    else
    {
        int flag; 
        fscanf(in,"%d", &flag);
        
        car_t *cars; 
        cars = (car_t *)malloc(sizeof(car_t) * flag); 
        
        readFile(in, cars, flag); 
        
        if (cars == NULL)
            printf("Issue with allocating memory\n");
        else
        {
            int choice;
            menu(&choice); 

            while (choice!= 6)
            {
                switch(choice)
                {
                    case 1: 
                    displayType(cars, flag);
                    break; 

                    case 2:
                    displayModel(cars, flag); 
                    break;

                    case 3: 
                    displayColor(cars, flag); 
                    break; 

                    case 4: 
                    displayKM(cars, flag); 
                    break; 

                    case 5: 
                    displayPrice(cars, flag); 
                }
                menu(&choice);
            }
        }
    }
    fclose(in);
    return(0);
}

void menu(int *choice)
{
    printf("Find according to:\n");
    printf("1. Type\n2. Model\n3. Color\n4. KM\n5. Price Range\n6. Exit\n\n");

    printf("Enter your choice: ");
    scanf("%d", choice); 

    while (*choice > 6 || *choice < 1)
    {
        printf("Please re-enter your choice [1-6]: ");
        scanf("%d", choice);
    }
}

void readFile(FILE *in, car_t *cars, int flag)
{
    int count = 0;  
    while(fscanf(in," %c %d %c %lf %lf", &(cars + count)->type, &(cars + count)->year, &(cars + count)->color, &(cars + count)->km, &(cars + count)->price) != EOF && (count < flag))
        count++; 
}

void displayType(car_t *cars, int size)
{
    char type; 
    int count = 0;
    printf("Type (P: Peugeot, M: Mercedes, H: Honda): "); 
    scanf(" %c", &type);
    convertoUpper(&type);

    printf("Type         Model    Color    Km           Price\n");
    printf("--------     -----    -----    ---------    -------------\n");
    for (int r = 0; r < size; r++)
        if ((cars + r)->type == type)
        {
            switch(type)
            {
                case 'M': 
                printf("%s    %5d     ", typeStr[0], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
                break;

                case 'P': 
                printf("%s     %5d     ", typeStr[1], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
                break;

                case 'H': 
                printf("%s       %5d     ", typeStr[2], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
            }
        }
    printf("\n");
    for (int r = 0; r < size; r++)
        if ((cars + r)->type != type)
            count++; 
    if (count == size)
        printf("There is no car that suits these conditions.\n\n");
}

void displayModel(car_t *cars, int size)
{
    int model; 
    int count = 0;
    printf("Model: "); 
    scanf("%d", &model);

    printf("Type         Model    Color    Km           Price\n");
    printf("--------     -----    -----    ---------    -------------\n");
    for (int r = 0; r < size; r++)
        if ((cars + r)->year == model)
        {
            switch((cars + r)->type)
            {
                case 'M': 
                printf("%s    %5d     ", typeStr[0], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
                break;

                case 'P': 
                printf("%s     %5d     ", typeStr[1], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
                break;

                case 'H': 
                printf("%s       %5d     ", typeStr[2], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
            }
        }
    printf("\n");
    for (int r = 0; r < size; r++)
        if ((cars + r)->year != model)
            count++; 
    if (count == size)
        printf("There is no car that suits these conditions.\n\n");
}

void displayColor(car_t *cars, int size)
{
    char color; 
    int count = 0;
    printf("Color(R: Red, B: Blue, W: White): "); 
    scanf(" %c", &color);
    convertoUpper(&color); 

    printf("Type         Model    Color    Km           Price\n");
    printf("--------     -----    -----    ---------    -------------\n");
    for (int r = 0; r < size; r++)
        if ((cars + r)->color == color)
        {
            switch((cars + r)->type)
            {
                case 'M': 
                printf("%s    %5d     ", typeStr[0], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
                break;

                case 'P': 
                printf("%s     %5d     ", typeStr[1], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
                break;

                case 'H': 
                printf("%s       %5d     ", typeStr[2], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
            }
        }
    printf("\n");
    for (int r = 0; r < size; r++)
        if ((cars + r)->color!= color)
            count++; 
    if (count == size)
        printf("There is no car that suits these conditions.\n\n");
}

void displayKM(car_t *cars, int size)
{
    double km1, km2; 
    int count = 0;
    printf("Km range: "); 
    scanf("%lf %lf", &km1, &km2);

    while (km1 >= km2)
    {
        printf("Please enter the range as f.i 1000 - 2000: ");
        scanf("%lf %lf", &km1, &km2);
    }

    printf("Type         Model    Color    Km           Price\n"); 
    printf("--------     -----    -----    ---------    -------------\n");
    for (int r = 0; r < size; r++)
        if ((cars + r)->km >= km1 && (cars + r)->km <=km2)
        {
            switch((cars + r)->type)
            {
                case 'M': 
                printf("%s    %5d     ", typeStr[0], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
                break;

                case 'P': 
                printf("%s     %5d     ", typeStr[1], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
                break;

                case 'H': 
                printf("%s       %5d     ", typeStr[2], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
            }
        }
    printf("\n");
    for (int r = 0; r < size; r++)
        if (!((cars + r)->km >= km1 && (cars + r)->km <=km2))
            count++; 
    if (count == size)
        printf("There is no car that suits these conditions.\n\n");
}
void displayPrice(car_t *cars, int size)
{
    double p1, p2;  
    int count = 0;
    printf("Price range: "); 
    scanf("%lf %lf", &p1, &p2);

    while (p1 >= p2)
    {
        printf("Please enter the range as (f.i 1000 - 2000): ");
        scanf("%lf %lf", &p1, &p2);
    }

    printf("Type         Model    Color    Km           Price\n");   
    printf("--------     -----    -----    ---------    -------------\n");
    for (int r = 0; r < size; r++)
        if ((cars + r)->km >= p1 && (cars + r)->km <=p2)
        {
            switch((cars + r)->type)
            {
                case 'M': 
                printf("%s    %5d     ", typeStr[0], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
                break;

                case 'P': 
                printf("%s     %5d     ", typeStr[1], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
                break;

                case 'H': 
                printf("%s       %5d     ", typeStr[2], (cars + r)->year);
                switch((cars + r)->color)
                {
                    case 'R': 
                    printf("Red      %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'B': 
                    printf("Blue     %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                    break;

                    case 'W': 
                    printf("White    %-9.2f    %-10.2f TL\n", (cars + r)->km, (cars + r)->price);
                }
            }
        }
    printf("\n");
    for (int r = 0; r < size; r++)
        if (!((cars + r)->km >= p1 && (cars + r)->km <=p2))
            count++; 
    if (count == size)
        printf("There is no car that suits these conditions.\n\n");
}

void convertoUpper(char *ch)
{
    if (*ch >= 'a' && *ch <= 'z')
        *ch -= 'a' - 'A'; 
}