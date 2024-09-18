/*
Reads employee information from a .txt file, 
txt file contains: 
(ssn | name | surname | gross salary | health ins type | BES status | sgk stoppage)

Details of stoppage for calculations: 
Private Health Insurance: Family 194 TL, Individual 97 TL.
- OtoBES: %3 of gross salary.
- SGK: stoppage is different for each employee and will be calculated out of the gross salary with the specified
percentage.

Following functions will be implemented: 
readEmpInfo, calcNetSalary, displayEmpInfo, bubbleSort. 

Program will calculate net payments accordingly and will display them
in descending form. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int ssn; 
    char name[20];
    char surname[20];
    double grossSal;
    char privHealthI[20];
    char besStat;
    int sgkStopPer; 
    double netSalary;
}employee_t;

int readEmpInfo(FILE *in, employee_t *employees, int maxSize); 

void calcNetSalary(employee_t *employees, int size);

void displayEmpInfo(employee_t *employees, int size); 

// For Bubble Sort Operation
void swap(employee_t *a, employee_t *b);

void bubbleSort(employee_t *employees, int size);

// Main Program
int main(void)
{
    FILE *in = fopen("employee.txt","r"); 

    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        int initSize = 50; // Max input

        employee_t *employees = (employee_t *)malloc(sizeof(employee_t) * initSize);
        if (employees == NULL)
            printf("Problem in allocating memory.\n"); 
        else
        {
            initSize = readEmpInfo(in, employees, initSize); // Actual size is attained, file is read
            calcNetSalary(employees, initSize);
            bubbleSort(employees, initSize);
            displayEmpInfo(employees, initSize); 
        }
    }
    return(0);
}

int readEmpInfo(FILE *in, employee_t *employees, int maxSize)
{
    int actSize = 0;
    while (fscanf(in,"%d %s %s %lf %s %c %d", &(employees + actSize)->ssn, (employees + actSize)->name, (employees + actSize)->surname, &(employees + actSize)->grossSal, (employees + actSize)->privHealthI, &(employees + actSize)->besStat, &(employees + actSize)->sgkStopPer)!= EOF && (actSize < maxSize))
        actSize++; 
    return(actSize); 
}

void calcNetSalary(employee_t *employees, int size)
{
    double temp;
    
    for (int i = 0; i < size; i++)
    {
        temp = 0;

        if (strcmp((employees + i)->privHealthI, "individual") == 0)
            temp -= 97;
        else if (strcmp((employees + i)->privHealthI, "family") == 0)
            temp -= 194;

        if ((employees + i)->besStat == 'Y')
            temp -= (employees + i)->grossSal * 3/100;
        
        temp -= (employees + i)->grossSal * (employees + i)->sgkStopPer / 100;

        (employees + i)->netSalary = (employees + i)->grossSal + temp;
    }
}

void displayEmpInfo(employee_t *employees, int size)
{
    printf("\n------------------------\n");
    printf("| Employee Information |\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("| SSN   Name         Surname       Health Insurance   BES   SGK     Gross Salary    Net Payment |\n");
    printf("| ***   *********    ***********   ****************   ***   ***     ************    *********** |\n");

    for (int r = 0; r < size; r++)
        printf("| %3d   %-9s    %-11s   %-16s    %c    %%%2d     %-7.2f TL     %-8.2f TL |\n", (employees + r)->ssn, (employees + r)->name, (employees + r)->surname, (employees + r)->privHealthI, (employees + r)->besStat, (employees + r)->sgkStopPer, (employees + r)->grossSal, (employees + r)->netSalary);

    printf("-------------------------------------------------------------------------------------------------\n\n");
}

void swap(employee_t *a, employee_t *b)
{
    employee_t temp = *a; 
    *a = *b;
    *b = temp; 
}

void bubbleSort(employee_t *employees, int size)
{
    int pass = 0, sorted; 

    do
    {
        sorted = 1;
        for (int k = 0; k < size - pass - 1; k++)
            if (strcmp((employees + k)->surname, (employees + k + 1)->surname) > 0)
            {
                swap((employees + k),(employees + k + 1));
                sorted = 0;
            }
        pass++;
    } while (!sorted);
}