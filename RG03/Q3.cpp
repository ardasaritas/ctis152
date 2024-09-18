#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_struct.h"

int main(void)
{
    FILE *in = fopen("companies.bin","rb");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        stackk_t s;
        initializeS(&s);

        fseek(in, 0, SEEK_END);
        int size = ftell(in) / sizeof(company_t); 
        rewind(in); 

        company_t *Ap = (company_t *)malloc(sizeof(company_t) * size);

        fread(Ap, sizeof(company_t), size, in);

        for (int r = 0; r < size; r++)
            push(&s, Ap[r]); 

        SType temp; 
        printf("Year  Company Name  Phone       Web URL\n");
        printf("****************************************************\n");
        while(!isEmptyS(&s))
        {
            temp = pop(&s);
            printf("%4d  %-12s  %-11s %s\n", temp.foundation, temp.companyName, temp.phone, temp.URL);
        }
    }
}