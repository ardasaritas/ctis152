#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_int.h"

int calculate(int op1, int op2, char oper);

int evalPostFix(char *string);

int main(void)
{
    char *str; 
    str = (char *)malloc(sizeof(char) * 30);
    printf("Enter an expression: ");
    scanf(" %s", str); 

    printf("The result is: %d\n", evalPostFix(str));
    return(0);
}

int calculate(int op1, int op2, char oper)
{
    int res;
     
    switch(oper)
    {
        case '+': 
        res = op1 + op2; 
        break;

        case '*':
        res = op1 * op2;    
        break;

        case '-':
        res = op2 - op1;
        break;

        case '/':
        res = op2 / op1;
    }
    return(res);
}

int evalPostFix(char *string)
{
    stackk_t s;
    initializeS(&s); 

    int temp, res; 

    for (int i = 0; i < strlen(string); i++)
        if (*(string + i) >= '0' && *(string + i) <= '9')
        {
            temp = *(string +i) - '0'; 
            push(&s, temp);
        }
        else
        {
            res = calculate(pop(&s), pop(&s), *(string + i));
            push(&s, res); 
        }
    return(pop(&s));
}