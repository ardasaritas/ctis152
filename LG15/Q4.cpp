#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_struct.h"

int main(void)
{
    FILE *in = fopen("commands.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n"); 
    else
    {
        char command[50][10]; 
        person_t *persons; 
        persons = (person_t *)malloc(sizeof(person_t) * 10); 

        stackk_t s; 
        initializeS(&s);

        int i = 0; 
        while(fscanf(in, " %s", command[i]) != EOF)
        {
            for (int r = 0; r < strlen(command[i]); r++)
                command[i][r] = toupper(command[i][r]);

            if (!strcmp(command[i], "POP"))
            {
                person_t tempPer = pop(&s);
                if (!isEmptyS(&s))
                    printf("%s age %2d is removed from the stack\n",  tempPer.name, tempPer.age);
            }
            else if (!strcmp(command[i], "DISPLAY"))
            {
                stackk_t temp = s; 
                printf("\nThe stack content is:\n");
                person_t tempPer2;
                while(!isEmptyS(&temp))
                {
                    tempPer2 = pop(&temp);
                    printf("%-6s  %2d\n", tempPer2.name, tempPer2.age);
                }
                printf("\n");
            }
            else if (!strcmp(command[i], "PUSH"))
            {
                fscanf(in, "%s %d", (persons + i)->name, &(persons + i)->age);
                push(&s, persons[i]); 
            }
            else
                printf("Invalid Command\n\n"); 
            i++;
        }
        fclose(in); 
        free (persons);
    }
    return (0);
}