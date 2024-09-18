#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[20]; 
    char surname[30]; 
}worker_t;

void convertLower(char *string); 

int readFile(FILE *in, worker_t *workers);

int search(char *string, char key);

int main(void)
{
    FILE *in = fopen("worker.txt","r");
    FILE *out = fopen("mails.txt","w");

    if (in == NULL)
        printf("Error has occured when opening file.\n");
    else
    {
        worker_t *workers; 
        workers = (worker_t *)malloc(sizeof(worker_t) * 20); 

        int actsize = readFile(in, workers); 
        
        for (int r = 0; r < actsize; r++)
            convertLower((workers + r)->surname); 


        for (int i = 0; i < actsize; i++)
        {
            char first[2] = {((workers + i)->name[0]), '\0'}; 
            strcat((workers + i)->surname, first);
            fprintf(out, "%s@abc.com.tr\n", (workers + i)->surname);
        }   
        printf("Completed succesfully. Check the output file.\n");
        free(workers); 
    }
    return(0);
}

void convertLower(char *string)
{
   int len = strlen(string);
    
   for (int r = 0; r < len; r++)
        if (*(string + r) >= 'A' && *(string + r) <= 'Z')
            *(string + r) += 'a' - 'A';
}

int readFile(FILE *in, worker_t *workers)
{
    int count = 0; 
    while(fscanf(in,"%s %s", (workers + count)->name, (workers + count)->surname) != EOF)
        count++; 
    return(count); 
}

int search(char *string, char key)
{
    int index = -1; 
    for (int r = 0; r < strlen(string); r++)
        if (*(string + r) == ' ')
        {
            index = r;
            return(index);
        }
    return(index);
}