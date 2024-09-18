#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define TYPED 100
#define TYPEO 55
#define COVID 0.025

typedef struct 
{
    char name[MAX];
    int id;
    char dept; 
    char type; 
    int extra;
    double extrafee; 
}worker_t;

void menu(int *choice); 

int readFile(FILE *in, worker_t *workers); //also fills the extra fee as 0

void calculateExtraFee(worker_t *workers, int size); 

void displayDepartment(worker_t *workers, int size, char dept);

void converToUpper(char *a); 

int main(void)
{
    FILE *in = fopen("healthEmployee.txt","r");

    if (in == NULL)
        printf("Error has occured when opening the input file.\n"); 
    else
    {
        int flag; 
        fscanf(in,"%d", &flag);

        worker_t *workers;
        workers = (worker_t *)malloc(sizeof(worker_t) * flag);

        if (workers == NULL)
            printf("Check the memory allocation.\n");
        else
        {
            int choice; 
            char key; 

            int actsize = readFile(in, workers);

            menu(&choice); 
            while (choice != 3)
            {
                switch(choice)
                {
                    case 1: 
                    calculateExtraFee(workers, actsize);
                    printf("\nExtra Fees are calculated.\n");
                    break;
                    
                    case 2:
                    printf("Enter the department you want to search for: ");
                    scanf(" %c", &key);
                    if (key != 'c' && key != 'C' && key != 'o' && key && 'O')
                    {
                        printf("This is not a department\n");
                        break;
                    }
                    converToUpper(&key);
                    displayDepartment(workers, actsize, key); 
                    break;
                }
                menu(&choice);
            }
        }
    }
    printf("Program is terminated.\n");
    return(0);
}

void menu(int *choice)
{
    printf("\nMenu:\n");
    printf("1. Calculate Extra Fee\n");
    printf("2. Display by Department\n");
    printf("3. Exit\n\n");

    do
    {
       printf("Enter your choice: ");
       scanf("%d", choice);
    } while (*choice > 3 || *choice < 1);
}

int readFile(FILE *in, worker_t *workers)
{
    int r = 0; 
    while (fscanf(in," %s %d %c %c %d", (workers + r)->name, &(workers + r)->id, &(workers + r)->dept, &(workers + r)->type, &(workers + r)->extra) != EOF)
    {
        (workers + r)->extrafee = 0; 
        r++;
    }
    return(r);
}

void calculateExtraFee(worker_t *workers, int size)
{
    for (int r = 0; r < size; r++)
    {
        switch((workers + r)->type)
        {
            case 'D':
            (workers + r)->extrafee += (workers + r)->extra * TYPED;
            break;
            
            case 'N':
            (workers + r)->extrafee += (workers + r)->extra * TYPEO;
        }

        if ((workers + r)->dept == 'C')
            (workers + r)->extrafee += (workers + r)->extrafee * COVID;
    }
}

void displayDepartment(worker_t *workers, int size, char dept)
{
    printf("Name         Id    Dept    Type    Extra Hour   Extra Fee\n");
    printf("---------------------------------------------------------\n");
    for (int r = 0; r < size; r++)
        if ((workers + r)->dept == dept)
            printf("%-12s %4d  %4c       %c        %2d         %7.2f\n",(workers + r)->name, (workers + r)->id, (workers + r)->dept, (workers + r)->type, (workers + r)->extra, (workers + r)->extrafee);
}

void converToUpper(char *a)
{
    if (*a >= 'a' && *a <= 'z')
        *a += 'A' - 'a'; 
}