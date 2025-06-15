#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack_int.h"

int convertToDecimal(int number, int base);

int main(void)
{
    int base, number;
    
    printf("Enter a number, than it's base ([num][base]): ");
    scanf("%d %d", &number, &base);

    printf("Decimal equivalent of the number is: %d\n", convertToDecimal(number, base));
    return(0);
}

int convertToDecimal(int number, int base)
{
    stackk_t stack;
    initializeS(&stack);   

    while (number != 0)
    {
        push(&stack, number % 10);
        number /= 10;  
    }

    int sum = 0;
    
    while(!isEmptyS(&stack))
    {
        int temp = pop(&stack);
        sum += temp * pow(base, stack.top + 1);  
    }
    return(sum);
}
