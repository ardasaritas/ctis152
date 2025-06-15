#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct
{
	char companyName[MAX];
	int saleRate; 
	int numOfPeople;
}company_t;

int readFromFile(FILE *in, company_t *arr);

void display(company_t *arr, int size);

int binarySearch(company_t *arr, int start, int finish, int key);

int main(void)
{
	FILE *in = fopen("fly.txt", "r");

	if (in == NULL)
		printf("Error has occurred when opening the input file.\n");
	else
	{
		int flag;
		fscanf(in, "%d", &flag);
		
		company_t *fly;
		fly = (company_t *)malloc(sizeof(company_t) * flag);

		int index, actsize = readFromFile(in, fly);
		int key;

		display(fly, actsize);
		printf("\n");
		do
		{
			printf("Enter number of people to see the campaign (or -1): ");
			scanf("%d", &key);

			if (key == -1)
				return(0);

			index = binarySearch(fly, 0, actsize - 1, key);

			if (index == -1)
				printf("%d could not be found\n\n", key);
			else
				printf("%s is found on the %d sale rate with %d people\n\n", (fly + index)->companyName, (fly + index)->saleRate, (fly + index)->numOfPeople);

		} while (key != -1);
	}
	return(0);
}

int readFromFile(FILE *in, company_t *arr)
{
	int count = 0;
	while (fscanf(in, " %[^0-9] %d %d", (arr + count)->companyName, &arr[count].saleRate, &arr[count].numOfPeople) != EOF && (count < MAX))
		count++;
	return(count);
}

void display(company_t *arr, int size)
{
	printf("      Fly Information for the companies\n");
	printf("--------------------------------------------\n");
	for (int r = 0; r < size; r++)
		printf("%-12s           %-2d           %2d\n", arr[r].companyName, arr[r].saleRate, arr[r].numOfPeople);
}

int binarySearch(company_t *arr, int start, int finish, int key)
{
	int mid;

	while (start <= finish)
	{
		mid = (start + finish) / 2;

		if (arr[mid].numOfPeople == key)
		{
			return(mid);
		}
		else if (arr[mid].numOfPeople > key)
		{
			finish = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return(-1);
}
