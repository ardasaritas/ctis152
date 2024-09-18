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

int main(void)
{
    FILE *inp = fopen("output.bin","rb");

    if (inp == NULL)
        printf("Error opening file.\n");
    else
    {
        robot n;
        
        rewind(inp);
        while (fread(&n, sizeof(robot), 1, inp) == 1)
            printf("%-25s   %4d     %s\n", n.name, n.madeDate, n.inventor);
    }
    return(0);
}