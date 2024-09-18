#include <stdio.h>
#include "queue_struct_stack.h"

void displayQueue(queue_t q);

void displayStack(stackk_t *s);

int main(void)
{
    FILE *in = fopen("courses.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        queue_t q;
        initializeQ(&q);
        char flag;

        stackk_t s;
        initializeS(&s);

        course_t temp;

        while(fscanf(in,"%d %d%c", &temp.code, &temp.credit, &flag) != EOF)
        {
            if (flag == '\r')
            {
                push(&s, temp);
                insert(&q, s);
                while(!isEmptyS(&s))
                    pop(&s);
            }
            else 
                push(&s, temp);
        }
        displayQueue(q);
    }
    fclose(in);
    return(0);
}

void displayQueue(queue_t q)
{
    printf("Queue Content\n");
    printf("-------------\n");
    
    stackk_t a;
    initializeS(&a);
    while(!isEmptyQ(&q))
    {
        a = remove(&q);
        displayStack(&a);
    }
    printf("\n");
}

void displayStack(stackk_t *s)
{
    while(!isEmptyS(s))
    {
        SType a = pop(s); 
        printf("%d %d--> ", a.code, a.credit);
    }
    printf("END\n");
}