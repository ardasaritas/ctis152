#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_struct2.h"

node_t *createList(FILE *in, node_t *hp);

node_t *searchUser(node_t *hp, char *user); 

void displaySelected(node_t *hp, char *user);

node_t *deleteUserLogins(node_t *hp, char *user);

void displayList(node_t *hp);

int main(void)
{
    FILE *in = fopen("alert.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        node_t *hp = NULL;
        hp = createList(in, hp);

        printf("Login information for the users who may habve suspicious activities:\n\n");
        
        printf("User Name       City             Last Login\n");
        printf("***********     *********        ****************\n");
        displayList(hp);

        char userToSearch[20];
        printf("Please enter your account name to see the login history: ");
        scanf(" %s", userToSearch);

        node_t *tp = searchUser(hp, userToSearch); 
        if (tp->next == NULL)
            printf("There is no account name with the name %s\n\n", userToSearch);
        else
        {
            displaySelected(hp, userToSearch);
            char choice;
            printf("Is there any suspicious account activity? (y/n): ");
            scanf(" %c", &choice);

            switch(choice)
            {
                case 'n':
                printf("*** All the login info will be deleted ***\n\n");
                hp = deleteUserLogins(hp, userToSearch);
                break;

                case 'y': 
                printf("All good!\n\n");
                break;
            }

            printf("User Name       City             Last Login\n");
            printf("***********     *********        ****************\n");
            displayList(hp);    
        }
        
    }
    fclose(in);
    return(0);
}

node_t *createList(FILE *in, node_t *hp)
{
    LType temp;
    fscanf(in," %[^,],%[^,],%[^\r]", temp.name, temp.city, temp.dateNtime);
    hp = addBeginning(hp, temp);
    node_t *tp = hp;

    while(fscanf(in," %[^,],%[^,],%[^\r]", temp.name, temp.city, temp.dateNtime) != EOF)
    {
        addAfter(tp, temp);
        tp = tp->next;
    }

    return(hp);
}

node_t *searchUser(node_t *hp, char *user)
{
    if (strcmp(hp->data.name, user) != 0)
        while (hp->next != NULL && strcmp(user, hp->next->data.name) != 0)
            hp = hp->next;
    
    return(hp);
}

void displaySelected(node_t *hp, char *user)
{
    printf("\n");
    do
    {
        if(!strcmp(hp->data.name, user))
            printf("%-11s     %-14s   %s ->\n", hp->data.name, hp->data.city, hp->data.dateNtime);
        hp = hp->next;
    } while (hp != NULL);
    printf("\n");
}

node_t *deleteUserLogins(node_t *hp, char *user)
{
    node_t *tp;
    tp = searchUser(hp , user);

    while (tp->next != NULL)
    {
        if (tp == hp && !strcmp(tp->data.name, user))
                hp = deleteBeginning(hp);
            else
                deleteAfter(tp);
        tp = searchUser(hp, user);
    }
    printf("Login history updated!\n\n");

    return(hp);
}

void displayList(node_t *hp)
{
    while (hp != NULL)
    {
        printf("%-11s     %-14s   %s ->\n", hp->data.name, hp->data.city, hp->data.dateNtime);
        hp = hp->next;
    }
    printf("NULL\n\n");
}