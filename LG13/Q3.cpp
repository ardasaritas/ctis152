#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sumDivisors(int div, int n);

int main(void)
{
	int num; 

	do
	{
		printf("Enter a non-negative number: ");
		scanf("%d", &num);
	} while (num <= 0);

	int sum = sumDivisors(num / 2, num);

	if (sum == num)
		printf("%d is a perfect number.\n", num);
	else
		printf("%d is not a perfect number.\n", num);
	
	return(0);
}

int sumDivisors(int div, int n)
{
	if (div == 1)
		return 1;
	
	if (n % div == 0)
		return(div + sumDivisors(div - 1, n));
	else
		return(sumDivisors(div - 1, n));
}
