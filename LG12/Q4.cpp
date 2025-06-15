/*****
Recursively implemented Ackermann algorithm. 
Checks m and n for both > 0 and m < 4.
*****/
#include <stdio.h>

int isAckermann(int m, int n); 

int main(void)
{
    int m, n;
    
    printf("Enter the value of m: ");
    scanf("%d", &m); 
    
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (m >= 0 && n >= 0)
        if (m < 4)
            printf("\nThe result is: %d\n", isAckermann(m, n)); 
        else 
            printf("\nm should be less than 4. Exiting...\n"); 
    else 
        printf("\nBoth m and n should be positive integers. Exiting...\n");
}   
    
int isAckermann(int m, int n)
{
    if (m == 0)
        return (n + 1); 
    else 
    {
        if (m > 0)
            if (n == 0)
                return isAckermann(m - 1, 1); 
            else
                return isAckermann(m - 1, isAckermann(m, n - 1));        
    }
}