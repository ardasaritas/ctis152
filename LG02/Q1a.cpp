// Examine the difference between pointer, adresses, values
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS_

int main(void)
{
	int x = 45, y;

	int *ptr_x = &x;

	int *ptr_y;

	*ptr_x = x + 3;

	y = *ptr_x + 10;

	ptr_y = ptr_x;

	*ptr_x = x + y;

	printf(" %p\n %p\n %p\n %d\n %d\n %p\n %d\n %p\n %d\n", &x, &y, ptr_x, *ptr_x, x, ptr_y, *ptr_y, (ptr_x + 3), (*ptr_x + 3));
}