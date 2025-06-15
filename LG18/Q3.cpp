#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_struct.h"

node_t *createList(FILE *in, node_t *hp);

void displayList(node_t *hp);

node_t *searchCountry(node_t *hp, char *country);

node_t *findWinner(node_t *hp);


int main(void)
{
    FILE *in = fopen("students.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        node_t *hp; 
        hp = NULL;
        hp = createList(in, hp); 
        displayList(hp);

        node_t *tp = findWinner(hp);
        printf("The winner: %s, %s, %s, %d\n\n", tp->data.name, tp->data.surname, tp->data.country, tp->data.numLines);

        char searchedCountry[20];
        printf("Enter a country to search: ");
        scanf(" %s", searchedCountry);

        tp = searchCountry(hp, searchedCountry);
        if (tp == NULL)
            printf("There is no student from %s\n\n", searchedCountry);
        else
            printf("%s, %s, %s, %d\n\n", tp->data.name, tp->data.surname, tp->data.country, tp->data.numLines);
    }
    fclose(in);
    return 0;
}

node_t *createList(FILE *in, node_t *hp)
{
    LType temp;
    fscanf(in," %s %s %s %d", temp.name, temp.surname, temp.country, &temp.numLines);
    hp = addBeginning(hp, temp);
    node_t *tp = hp;

    while (fscanf(in," %s %s %s %d", temp.name, temp.surname, temp.country, &temp.numLines) != EOF)
    {
        addAfter(tp, temp);
        tp = tp->next;
    } 
    return (hp);
}

void displayList(node_t *hp)
{
    printf("Name     Surname    Country      #OfLines\n");
    printf("******   *********  *********    ********\n");
    while (hp != NULL)
    {
        printf("%-6s   %-8s   %-9s     %-4d  ->\n", hp->data.name, hp->data.surname, hp->data.country, hp->data.numLines);
        hp = hp->next;
    }
    printf("NULL\n\n");
}

node_t *searchCountry(node_t *hp, char *country)
{
    while (hp != NULL && strcmp(hp->data.country,country) != 0)
        hp = hp->next;
    return(hp);
}

node_t *findWinner(node_t *hp)
{
    node_t *winner; 
    int max = hp->data.numLines;
    hp = hp->next;

    while (hp != NULL)
    {
        if (hp->data.numLines > max)
        {
            max = hp->data.numLines;
            winner = hp;
        }
        hp = hp->next;
    }
    return(winner);
}