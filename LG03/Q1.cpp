#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 

int main(void)
{
	double array[4][3] = { {69.11, 25.23, 48.79}, {81.25, 63.47, 42.14 }, {99.1, 52.63, 38.21}, {11.23,45.58,12.49} };

	printf("%p\n%p\n%p\n%p\n%f\n%f\n%f\n%p\n%f\n", array, array + 1, *(array + 1), (*(array)+1), *(*(array)+1), *(*(array + 1)), *(*(array)+1) + 2, (*(array + 1) + 2), *(*(array + 1) + 2));
}
