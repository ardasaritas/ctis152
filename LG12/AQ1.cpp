/*****
Searches a list of users by prompting the user on which username to search. 
Uses recursive binary search and recursive bubble sort algorithms.
*****/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

typedef struct 
{
    char username[20]; 
    char name[20];
    char surname[20];
    char phoneNumber[20]; 
}user_t;

int readFromFile(FILE *in, user_t *users);

void convertSpaceToDash(char *str); 

void display(user_t *users, int size);

void swap(user_t *a, user_t *b);

void recBubbleSort(user_t *users, int size);

int binarySearchRec(user_t *users, int start, int finish, char *key);

int main(void)
{
    FILE *in = fopen("userinfo.txt", "r");

    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        user_t *users;
        users = (user_t *)malloc(sizeof(user_t) * MAX);

        if (users == NULL)
            printf("Check memory allocation.\n"); 
        else
        {
            int actSize = readFromFile(in, users); 
            recBubbleSort(users, actSize);
            display(users, actSize);

            char str[30];
            printf("\nEnter the username (END for exit): ");
            scanf(" %s", str);

            while (strcmp(str, "END") != 0)
            { 
                int index = binarySearchRec(users, 0, actSize - 1, str);
                
                if (index != -1)
                    printf("%-15s    %-12s   %-13s %-13s\n\n", (users + index)->username, (users + index)->name, (users + index)->surname, (users + index)->phoneNumber);
                else    
                    printf("The searched username is not on the list.\n\n");

                printf("Enter the username (END for exit): ");
                scanf(" %s", str);
            }         
        }
        free(users);
    }
    return(0); 
}

int readFromFile(FILE *in, user_t *users)
{
    int count = 0; 
    while (fscanf(in, " %s %s %s %s", (users + count)->username, (users + count)->name, (users + count)->surname, (users + count)->phoneNumber) != EOF)
        count++;
    fclose(in);
    return(count);
}

void convertSpaceToDash(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        if (isblank(*(str + i)) != 0)
            *(str + i) = '-';
}

void display(user_t *users, int size)
{
    printf("There are %d users in the list\n\n", size);
    printf("Username           Name           Surname           Phone\n");
    printf("***************    ************   ************* *************\n");

    for (int i = 0; i < size; i++)
    {
        convertSpaceToDash((users + i)->phoneNumber); 
        printf("%-15s    %-12s   %-13s %-13s\n", (users + i)->username, (users + i)->name, (users + i)->surname, (users + i)->phoneNumber);
    }
}

void swap(user_t *a, user_t *b)
{
    user_t temp = *a;
    *a = *b;
    *b = temp;
}

/*void recBubbleSort(user_t *users, int sorted, int pass, int k, int size)
{
    if (!sorted) // If the list is not sorted
    {
        sorted = 1; // Assume sorted
        for (int k = 0; k < size - pass; k++)
            if (strcmp((users + k)->username, (users + k + 1)->username) > 0)
            {
                swap((users + k), (users + k + 1));
                sorted = 0;
            }
        return recBubbleSort(users, sorted, pass + 1, k + 1, size); // Change the pass and k parameters by +1
    }
}*/

void recBubbleSort(user_t *users, int size)
{
    int sorted = 1; // Assume sorted
    for (int k = 0; k < size - 1; k++)
        if (strcmp((users + k)->username, (users + k + 1)->username) > 0)
        {
            swap((users + k), (users + k + 1));
            sorted = 0;
        }

    if (!sorted) // If the list is not sorted
        recBubbleSort(users, size - 1); 
}

int binarySearchRec(user_t *users, int start, int finish, char *key)
{
    if (start > finish)
        return(-1); 
    else
    {
        int mid = (start + finish) / 2;

        if (strcmp((users + mid)->username, key) == 0)
            return(mid);
        else if (strcmp((users + mid)->username, key) > 0)
            return(binarySearchRec(users, start, mid - 1, key));
        else
            return(binarySearchRec(users, mid + 1, finish, key));
    }
}