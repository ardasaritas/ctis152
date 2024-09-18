#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList_int.h"
#include <time.h>

void createTextFile(FILE *in, char *name); // randomly generates numbers and creates a file

node_t *createSortedList(char *nameOfFile, node_t *hp); // takes the numbers from the file and creates a sorted list

node_t *mergeLists(node_t *hp, node_t *hp1); // merges lists without creating another

int main(void)
{
    char file1[20];
    char file2[20];

    printf("Enter the first file's name: ");
    scanf(" %s", file1);
    FILE *in1 = fopen(file1, "w"); 
    createTextFile(in1, file1);

    printf("Enter the second file's name: ");
    scanf(" %s", file2);
    FILE *in2 = fopen(file2, "w"); 
    createTextFile(in2, file2);

    node_t *hp = NULL, *hp1 = NULL;
    hp = createSortedList(file1, hp);
    hp1 = createSortedList(file2, hp1);

    printf("First list is: ");
    displayList(hp);
    printf("Second list is: ");
    displayList(hp1);

    hp = mergeLists(hp, hp1);

    printf("Merge List: ");
    displayList(hp);

    return(0);

}

void createTextFile(FILE *in, char *name)
{    
    int num;

    printf("How many numbers to generate? ");
    scanf("%d", &num);

    srand(time(NULL));
    int random; 
    for (int r = 0; r < num; r++)
    {
        random = rand() % (100) + 1; 
        printf("%d ", random);
        fprintf(in, "%d ", random); 
    }
    
    fclose(in);

    printf("\nFile <%s> is created.\n\n", name);
}

node_t *createSortedList(char *nameOfFile, node_t *hp)
{
    FILE *in = fopen(nameOfFile, "r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        LType temp;
        
        fscanf(in,"%d", &temp);
        hp = addBeginning(hp, temp);

        while(fscanf(in,"%d", &temp) != EOF)
        {
            if (temp < hp->data) // if less add first 
                hp = addBeginning(hp, temp);
            else // if not first, traverse the rest until the greater next is found
            {
                node_t *tp = hp;
                while(tp->next != NULL && temp > tp->next->data)
                    tp = tp->next; 

                addAfter(tp, temp);
            } 
        }
    }
    fclose(in);
    return(hp);
} 

node_t *mergeLists(node_t *hp, node_t *hp1)
{
    while (hp != NULL)
    {
        if (hp->data < hp1->data)
            hp1 = addBeginning(hp1, hp->data);
        else
        {
            node_t *tp = hp1;
            while(tp->next != NULL && hp->data > tp->next->data)
                tp = tp->next; 

            addAfter(tp, hp->data);
        }
        hp = hp->next;
    }

    return(hp1);
}