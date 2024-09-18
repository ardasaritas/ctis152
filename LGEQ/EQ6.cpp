#include <stdio.h>
#include <stdlib.h>
#include "stack_char.h"

void displayStack(stackk_t s);

int isLower(char ch);

void remAllLowCaseLet(stackk_t *s, int *count);

int main(void)
{
    stackk_t s;
    initializeS(&s);

    char ch;
    
    printf("Enter a character (or ! to stop): ");
    scanf(" %c", &ch);
    
    while (ch != '!')
    {
        push(&s, ch); 
        printf("Enter a character (or ! to stop): ");
        scanf(" %c", &ch);
    }
    displayStack(s); 
    int count = 0;
    remAllLowCaseLet(&s, &count);
    if (count != 0)
    {
        printf("The # of lowercase letters in the stack is: %d\n", count);
        printf("All lowercase letters are deleted.\n");
        displayStack(s);
    }
    
    

    if (count == 0)
        printf("The stack does not contain any lowercase letters.\n");

    return(0); 
}

void displayStack(stackk_t s)
{
    printf("\nThe content of the stack:\n");
    while(!isEmptyS(&s))
        printf("%c ", pop(&s));
    printf("\n\n");
}

int isLower(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return 1;
    else 
        return 0;
}

void remAllLowCaseLet(stackk_t *s, int *count)
{
    stackk_t temp;
    initializeS(&temp);

    while(!isEmptyS(s))
    {
        char item = pop(s); 
        if (!isLower(item))
            push(&temp, item);
        else (*count)++;
    }

    while(!isEmptyS(&temp))
        push(s, pop(&temp));
}
