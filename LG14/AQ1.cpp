#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_int.h"

void menu(int *choice);

int main(void)
{
    stackk_t s;
    initializeS(&s);
    int choice; 

    int num, r = 2; 
    printf("Fill the stack:\n");

    printf("Enter number 1: ");
    scanf("%d", &num);
    while (num != -9)
    {
        push(&s, num);
        printf("Enter number %d (-9 to end): ", r++);
        scanf("%d", &num);
    }

    int size = countStack(&s);

    menu(&choice);
    while(choice != 4)
    {
        switch(choice)
        {
            case 1: 
            printf("\nStack Content:\n");
            printf("*****************\n");
            displayStack(&s, size);
            printf("\n\nNumber of elements in the stack: %d\n", countStack(&s));
            break;

            case 2:
            remMaxStack(&s);
            size--;
            displayStack(&s, size);
            break;

            case 3:
            int N;
            printf("Enter N: ");
            scanf("%d", &N);
            sendNthToEnd(&s, N);
            displayStack(&s, size);
        }
        menu(&choice);
    }
    return(0);
}

void menu(int *choice)
{
    printf("\n       MENU\n");
    printf("**************************\n");
    printf("1) Count Stack\n");
    printf("2) Remove Maximum Element\n");
    printf("3) Send Nth to End\n");
    printf("4) Exit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", choice);
    } while (*choice > 4 || *choice < 1);
}
    