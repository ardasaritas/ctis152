#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[20];
    int yearFound;
    double numOfMon; 
}companyInfo_t;

typedef struct 
{
    char agencyName[20];
    char prodType[10];
    companyInfo_t companyInfo; 
}agency_t;

int readFromFile(FILE *in, agency_t *agencies);

void displayAllViews(agency_t *agencies, int size);

int findMaxMonitoredIndex(agency_t *agencies, int size);

int main(void)
{
    FILE *in = fopen("adCompanies.txt","r");

    if (in == NULL)
        printf("Error has occurred when opening the input file.\n"); 
    else
    {
        int flag;
        fscanf(in,"%d", &flag);

        agency_t *agencies; 
        agencies = (agency_t *)malloc(sizeof(agency_t) * flag);

        if (agencies == NULL)
            printf("Check the memory allocation.\n");
        else
        {
            int actsize = readFromFile(in, agencies);

            displayAllViews(agencies, actsize);

            int index = findMaxMonitoredIndex(agencies, actsize);

            printf("The winner of the compeition is -> %s\n", (agencies + index)->companyInfo.name);
        }
    }
    return(0); 
}

int readFromFile(FILE *in, agency_t *agencies)
{
    int r = 0; 
    while (fscanf(in," %s %s %s %d %lf", (agencies + r)->agencyName, (agencies + r)->prodType, (agencies + r)->companyInfo.name, &(agencies + r)->companyInfo.yearFound, &(agencies + r)->companyInfo.numOfMon) != EOF)
        r++;
    return(r);
}

void displayAllViews(agency_t *agencies, int size)
{
    for (int r = 0; r < size; r++)  
    {
        printf("From the agency %s, %s (%s) founded in %d\nViews: ", (agencies + r)->agencyName, (agencies + r)->companyInfo.name, (agencies + r)->prodType, (agencies + r)->companyInfo.yearFound);

        if ((agencies + r)->companyInfo.numOfMon > 1000000)
            printf("%0.0f.%d M\n\n", (agencies + r)->companyInfo.numOfMon / 1000000, (int) (agencies + r)->companyInfo.numOfMon / 100000 - (int) (agencies + r)->companyInfo.numOfMon / 1000000 * 10);
        else if ((agencies + r)->companyInfo.numOfMon > 1000)
            printf("%0.1f K\n\n", (agencies + r)->companyInfo.numOfMon / 1000);
        else 
           printf("%0.0f\n\n", (agencies + r)->companyInfo.numOfMon); 
    }    
}

int findMaxMonitoredIndex(agency_t *agencies, int size)
{
    int index;
    double max = agencies->companyInfo.numOfMon;

    for (int r = 0; r < size; r++)
        if ((agencies + r)->companyInfo.numOfMon > max)
        {
            max = ((agencies + r)->companyInfo.numOfMon);
            index = r;
        }
    return(index);
}