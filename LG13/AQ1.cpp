#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int validateBase(char *number, int base)
{
    if (*number == '\0')
        return 1;
    
    if (base <= 0 || base > 16)
        return 0; 
    else
    {
        if (*number - '0' >= base)
            return 0;
        else 
            return validateBase(number + 1, base);
    }
}

int convertDecimal(char *number, int base)
{
    if (strlen(number) > 0)
        return powf(base, strlen(number) - 1) * ((*number) - '0') + convertDecimal(number + 1, base);
    else
        return 0;
}


int main(void)
{
    char num[15];
    int base; 

    printf("Enter a number: ");
    scanf("%s", num);

    do
    {
        printf("Enter a base: ");
        scanf("%d", &base);
    } while (!validateBase(num, base));
    
   printf("The decimal is: %d\n", convertDecimal(num, base));

   return(0);
}