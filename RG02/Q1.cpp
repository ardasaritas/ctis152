#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[20];
    int age; 
    double gpa; 
} stu_t;

int showMenu(stu_t *students); 
 
int main(void)
{
    FILE *in = fopen("stu.bin","rb"); 

    if (in == NULL)
        printf("Error has occured when opening input file.\n");
    else
    {
        fseek(in, 0, SEEK_END);
        int size = ftell(in) / sizeof(stu_t); 

        stu_t *students = (stu_t *)malloc(sizeof(stu_t) * size); 
        
        rewind(in);
        fread(students, sizeof(stu_t), size, in); 
        fclose(in);

        int choice = showMenu(students), x, x2, x3; 
        while (choice != 4)
        {
            switch(choice)
            {
                case 1: 
                printf("Enter x: ");
                scanf("%d", &x);
                printf("\n%s %d %0.2f\n\n", (students + x - 1)->name, (students + x - 1)->age, (students + x - 1)->gpa);
                break;

                case 2:
                printf("Enter x: ");
                scanf("%d", &x2); 
                printf("\n%s %d %0.2f\n\n", (students + x + x2 - 1)->name, (students + x + x2 - 1)->age, (students + x + x2 - 1)->gpa);
                break;

                case 3: 
                printf("Enter x: ");
                scanf("%d", &x3); 
                printf("\n%s %d %0.2f\n\n", (students + size - x3)->name, (students + size - x3)->age, (students + size - x3)->gpa);
                break; 
            }
            choice = showMenu(students);
        }
    }
    return(0);
}

int showMenu(stu_t *students)
{
    int choice; 

    printf("1) Go to record X from top\n");
    printf("2) Move X record ahead\n");
    printf("3) Go X records back from bottom\n");
    printf("4) Exit\n\n");
    
    do
    {
    printf("Enter your choice: ");
    scanf("%d", &choice);
    } while (choice > 4 || choice < 0);
    
    return choice; 
}