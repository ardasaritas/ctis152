// Examine the difference between pointer, adresses, values
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int arr[9] = { 27, 16, 8, 19, 77, 99, 963, 813, 51 };

	printf("%p\n%p\n%d\n%d\n%p\n%d\n", arr, arr + 2, *(arr + 2), *arr + 4, arr + 5, *(arr + 7));
}
