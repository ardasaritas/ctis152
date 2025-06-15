#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_struct3.h"

void menu(int *choice);

void projectsToStack(FILE *bin, stackk_t *s);

void display(FILE *bin, stackk_t s); 

void completeProject(stackk_t *s, int position);

void addNewProject(stackk_t *s);

int main(void)
{
    FILE *binTeams = fopen("teams.bin", "rb");
    FILE *binProjects = fopen("projects.bin","rb");
    if (binTeams == NULL || binProjects == NULL)
        printf("Error has occured when opening one of the input files\n");
    else
    {
    stackk_t s;
    initializeS(&s);
    
    char name[20];

    projectsToStack(binProjects, &s);

    int choice, flag = 0; 
    menu(&choice); 

    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            display(binTeams, s); 
            break;
        
        case 2: 
            printf("Enter the project name to complete: ");
            scanf(" %s", name);
            int i, index;
            for (i = 0; i <= s.top; i++)
                if(!strcmp(s.data[i].projectName, name))
                {
                    index = i;
                    flag = 1; 
                }
            if (flag)
                completeProject(&s, index);
            else 
                printf("There is no project belonging to %s\n\n", name); 
            flag = 0;
            break;

        case 3: 
            addNewProject(&s); 
            break; 
        }
        menu(&choice);
    }
    fclose(binProjects);
    fclose(binTeams);
    return(0);
    }
}

void menu(int *choice)
{
    printf("\n       MENU\n");
    printf("************************\n");
    printf("1. Display all of the jobs\n");
    printf("2. Complete a project\n");
    printf("3. Add a new project\n");
    printf("4. Exit\n\n");
    
    do
    {
        printf("Enter your choice: ");
        scanf("%d", choice); 
    } while (*choice < 1 || *choice > 4);
}


void projectsToStack(FILE *bin, stackk_t *s)
{
    int size; 
    fseek(bin, 0, SEEK_END);
    size = ftell(bin) / sizeof(project_t); 

    rewind(bin);

    project_t *Ap = (project_t *)malloc(sizeof(project_t) * size);
    fread(Ap, sizeof(project_t), size, bin);

    for (int i = 0; i < size; i++)
        push(s, Ap[i]);
}

void display(FILE *bin, stackk_t s)
{
    while (!isEmptyS(&s))
    {
        char str[20] = ""; 
        project_t temp = pop(&s);
        printf("Project: %s, profit: %0.2f TL\n", temp.projectName, temp.profit);
        
        fseek(bin,((temp.team[0] - 5000) * 44 + 4), SEEK_SET);
        fread(str, sizeof(char), 20, bin);
        printf("%d %s ", temp.team[0], str);
        fread(&str[0], sizeof(char), 20, bin);
        printf("%s\n", str);
     
        fseek(bin,((temp.team[1] - 5000) * 44 + 4), SEEK_SET);
        fread(&str[0], sizeof(char), 20, bin);
        printf("%d %s ", temp.team[1], str);
        fread(&str[0], sizeof(char), 20, bin);
        printf("%s\n", str);
     
        fseek(bin,((temp.team[2] - 5000) * 44 + 4), SEEK_SET);
        fread(&str[0], sizeof(char), 20, bin);
        printf("%d %s ", temp.team[2], str);
        fread(&str[0], sizeof(char), 20, bin);
        printf("%s\n", str);
        printf("**************************************\n\n");
    }
}

void completeProject(stackk_t *s, int position)
{
   printf("\nCongratulations :)\n");
   printf("You have finished the %s's project.\n",s->data[position].projectName);
   printf("You will get %0.2f TL profit from this project.\n\n", s->data[position].profit);

   for (int r = position; r < s->top; r++)
        s->data[r] = s->data[r + 1];
    s->top--;
}

void addNewProject(stackk_t *s)
{
    project_t temp; 

    printf("Enter the project name : ");
    scanf(" %s", temp.projectName);
    printf("Enter the profit : ");
    scanf("%lf", &temp.profit);
    printf("Enter three team codes : ");
    scanf("%d %d %d", &temp.team[0], &temp.team[1], &temp.team[2]);

    push(s, temp);
    printf("\nNew job is added to the list\n\n");
}