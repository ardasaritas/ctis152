#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_struct.h"

int main(void)
{
	comp_t item;
	stackk_t S;

	initializeS(&S);

	FILE *bin = fopen("Competitions.bin", "rb");

	while (fread(&item, sizeof(item), 1, bin) == 1)
		push(&S, item);

	printf("Competition Name                                   Start Time               End Time\n");
	printf("*************************************************************************************************\n");
	while (!isEmptyS(&S)) 
	{
		comp_t temp;
		temp = pop(&S);
		printf("%-50s %-24s %-24s\n", temp.name, temp.startTime, temp.endTime);
	}
	printf("\n");
	return(0);
}
