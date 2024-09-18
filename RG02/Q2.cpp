#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct 
{
    char name[60]; 
    int madeDate; 
    char inventor[40]; 
} robot;

void print(robot *robots, int size);

void swap(robot *a, robot *b);

void bubbleSort(robot *robots, int size);

int recBinarySearch(robot *robots, int start, int finish, char *key);

int main(void)
{
    FILE *in = fopen("robots.txt","r"); 
    FILE *out = fopen("output.bin","wb");

    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        robot *robots = (robot *)malloc(sizeof(robot) * MAX);
        int r = 0;
        
        while (fscanf(in, " %[^:] : %d %[^\r]", (robots + r)->name, &(robots + r)->madeDate, (robots + r)->inventor) != EOF && (r < MAX))
            r++;
        fclose(in);

        bubbleSort(robots, r); 
        fwrite(robots, sizeof(robot), r, out);
        print(robots, r);
        
        char key[60];

        printf("Please enter a robot name to search: ");
        scanf(" %[^\n]", key); 

        if (recBinarySearch(robots, 0, r, key) == -1)
            printf("%s is not on the list\n", key); 
        else
            printf("%s is %d. robot in the list\n", key, recBinarySearch(robots, 0, r, key) + 1); 
        
        free(robots);
    }
    fclose(out);
    return(0);
}

void print(robot *robots, int size)
{
    printf("ROBOT NAME                  DATE     INVESTOR\n");
    printf("*************************************************************************\n");
    for (int i = 0; i < size; i++)
        printf("%-25s   %4d     %s\n", (robots + i)->name, (robots + i)->madeDate, (robots + i)->inventor);
    printf("\n");
}

void swap(robot *a, robot *b)
{
    robot temp; 
    temp = *a;
    *a = *b; 
    *b = temp;
}

void bubbleSort(robot *robots, int size)
{
    int pass = 1, sorted, k;

    do
    {
        sorted = 1; 
        for (k = 0; k < size - pass; k++)
            if (strcmp((robots + k)->name, (robots + k + 1)->name) > 0)
            {
                swap(robots + k, robots + k + 1);
                sorted = 0; 
            }
        pass++;
    } while (!sorted);
}

int recBinarySearch(robot *robots, int start, int finish, char *key)
{
    if (start > finish)
        return -1; 
    else
    {
        int mid = (start + finish) / 2; 

        if (strcmp((robots + mid)->name,key) == 0)
            return mid; 
        else if (strcmp((robots + mid)->name, key) > 0)
            return recBinarySearch(robots, start, mid - 1, key); 
        else    
            return recBinarySearch(robots, mid + 1, finish, key); 
    }
}