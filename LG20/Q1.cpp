#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_struct.h"

#define SIZE 10

int hashCode(char *username); //finds the hash index by using the sum of each letter's ascii code

void initArray(node_t *Hp[]); // initializes the headp array

void menu(int *choice); // shows the menu, reads the user's choice, validates

node_t *searchUser(node_t *hp, char *username);

void insertUser(node_t *Hp[], LType user);

void removeUser(node_t *Hp[], char *username);

void display(node_t *Hp[]);

int main(void)
{
    node_t *hp[SIZE];
    initArray(hp);

    int choice;
    LType temp;

    menu(&choice);
    while (choice != 4)
    {
        switch(choice)
        {
            case 1: 
                printf("Enter username and password: ");
                scanf(" %s %s", temp.username, temp.password);
                insertUser(hp, temp);
            break;

            case 2: 
                printf("Enter username and password: ");
                scanf(" %s %s", temp.username, temp.password);
                removeUser(hp, temp.username);
            break;

            case 3:
                display(hp);
            break;
        }         
        menu(&choice);   
    }
    return 0;
}

int hashCode(char *username)
{
    int sum = 0, len = strlen(username);

    for (int r = 0; r < len; r++)
        sum += username[r];
    
    return (sum % 10);
}

void initArray(node_t *Hp[])
{
    for (int r = 0; r < SIZE; r++)
        Hp[r] = NULL;
}

void menu(int *choice)
{
    printf("\n                MENU\n");
    printf("************************************\n");
    printf("1. Insert a user into the hash table\n");
    printf("2. Remove a user from the hash table\n");
    printf("3. Display a hash table\n");
    printf("4. Exit\n");
    printf("************************************\n\n");

    do
    {
        printf("Please enter your choice: ");
        scanf("%d", choice);
    } while (*choice > 4 || *choice < 1);
}

node_t *searchUser(node_t *hp, char *username)
{
    while (hp != NULL && strcmp(hp->data.username,username) != 0)
        hp = hp->next; 
    return(hp);
}

void insertUser(node_t *Hp[], LType user)
{
    int index = hashCode(user.username);
    node_t *addp, *tp;

    if (Hp[index] == NULL) // list is empty
    {
        Hp[index] = addBeginning(Hp[index], user); // add to the beginning of the linked list
        printf("User is inserted.\n");
    }
    else 
    {
        addp = searchUser(Hp[index], user.username); 
        if (addp != NULL) // exists, update the password only
        {
            strcpy(addp->data.password, user.password);
            printf("Password is updated.\n");
        }
        else // does not exist
        {
            tp = Hp[index];
            while (tp->next != NULL) // go to the last node
                tp = tp->next;
            addAfter(tp, user); // add after
            printf("User is inserted.\n");
        }
    }
}

void removeUser(node_t *Hp[], char *username)
{
    int index = hashCode(username);

    if (Hp[index] == NULL) // list is empty
        printf("The list does not include %s", username);
    else // list is not empty
    {
       if (strcmp(Hp[index]->data.username, username) == 0) // if first element
		{
			Hp[index] = deleteBeginning(Hp[index]);
			printf("\nUser which has the username %s is removed.\n", username);
		}
        else // if not the first
        {
            node_t *ptr = Hp[index];
			while (ptr->next != NULL && strcmp(ptr->next->data.username, username) != 0) // find the previous address
				ptr = ptr->next;

			if (ptr != NULL) // if found
			{
				deleteAfter(ptr);
				printf("\nUser which has the username %s is removed.\n", username);
			}
			else // if not in the list
				printf("This username does not exist.\n");
        }
    }
}

void display(node_t *Hp[])
{
    printf("\n");
    for (int r = 0; r < SIZE; r++)
    {
        node_t *temp = Hp[r];

        if (temp == NULL)
            printf("List [%d] has no elements\n", r + 1);
        else
        {
            printf("List [%d] : ", r + 1);
            while (temp != NULL)
            {
                printf("%s %s -> ", temp->data.username, temp->data.password);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}