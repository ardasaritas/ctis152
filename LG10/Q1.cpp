#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 15; 

void swap(int *a, int *b)
{
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

void bubbleSort(int *pc, int size)
{
    int pass = 0, sorted; 

    do
    {
        sorted = 1; 
        for (int k = 0; k < size - pass - 1; k++)
            if (*(pc + k) > *(pc + k + 1))
            {
                swap(pc + k, pc + k + 1); 
                sorted = 0; 
            }
        pass++;
    } while (!sorted);
}

int main(void)
{
    FILE *in = fopen("labs.txt","r"); 

    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        int *pc; 
        pc = (int *)malloc(sizeof(int) * MAX); 

        if (pc == NULL)
            printf("Problem with memory allocation.\n"); 
        else
        {
            int count = 0; 
            while (fscanf(in, "%d", pc + count) != EOF && (count < MAX))
                count++; 
            fclose(in); 

            bubbleSort(pc, count); 

            printf("Ascending Order\n");
            for (int i = 0; i < count; i++)
                printf("%d\n", *(pc + i));
        }
    }
    return(0);
}