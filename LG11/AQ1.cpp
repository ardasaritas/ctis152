#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void menu(int *choice);

int readFromFile(FILE *in, char names[][MAX]);

void display(char names[][MAX], int size);

void swap(char str1[], char str2[]);

void bubbleSort(char names[][MAX], int size);

int binarySearch(char names[][MAX], int start, int finish, char key[]);

int shiftDown(char names[][MAX], char added[], int size);

void addToList(char names[][MAX], char added[], int size);

int main(void)
{
	FILE *in = fopen("hotels.txt", "r");

	if (in == NULL)
		printf("Error has occurred when opening the input file.\n");
	else
	{
		char names[MAX][MAX] = {'\0'}, hotelname[MAX];

		int actsize = readFromFile(in, names), choice, flag = 0;

		bubbleSort(names, actsize);
		display(names, actsize);
		menu(&choice);
		
        while (choice != 3)
		{
			switch (choice)
			{
			case 1: 
				display(names, actsize);
				break;
			case 2:
				printf("\nPlease enter the hotel name: ");
				scanf(" %[^\n]", hotelname);
				
                hotelname[strlen(hotelname)] = '\r'; // When prompting, scanf does not capture '\r', if not added manually, strcmp below does not work as expected
                          
				for (int r = 0; r < actsize; r++)
					if (strcmp(names[r], hotelname) == 0)
						flag++;
                
                hotelname[strlen(hotelname) - 1] = '\0'; // Our string is not properly null terminated, thus if this statement is not executed, printf below does not work as expected

                if (flag != 0)
					printf("%s already exists in the list!\n\n", hotelname);
				else
				{
					addToList(names, hotelname, actsize);
					printf("%s is added to the list.\n\n", hotelname);
					actsize++;
				}
			}
			menu(&choice);
			flag = 0;
		}
	}
	return(0);
}

void menu(int *choice)
{
	printf("Menu\n");
	printf("****************\n");
	printf("1. Display the Hotel List\n");
	printf("2. Add a new hotel\n");
	printf("3. EXIT\n");

	printf("Please enter your choice: ");
	scanf("%d", choice);

	while (!(*choice <= 3 && *choice >= 1))
	{
		printf("Please re-enter your choice: ");
		scanf("%d", choice);
	}
}

int readFromFile(FILE *in, char names[][MAX])
{
	int count = 0;
	while (fscanf(in, " %[^\n]", names[count]) != EOF && (count < MAX))
		count++;
	return(count);
}

void display(char names[][MAX], int size)
{
	printf("\nHotel List\n");
	printf("-----------------------\n");

	for (int i = 0; i < size; i++)
		printf("%d) %s\n", i + 1, names[i]);
	printf("\n");
}

void swap(char str1[], char str2[])
{
	char temp[MAX];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

void bubbleSort(char names[][MAX], int size)
{
	int k, pass, sorted;
	pass = 1;

	do
	{
		sorted = 1;
		for (k = 0; k < size - pass; k++)
			if (strcmp(names[k], names[k + 1]) > 0)
			{
				swap(names[k], names[k + 1]);
				sorted = 0;
			}
		pass++;
	} while (!sorted);
}

int binarySearch(char names[][MAX], int start, int finish, char key[])
{
	int mid;

	while (start <= finish)
	{
		mid = (start + finish) / 2;

		if (strcmp(names[mid], key) == 0)
			return(mid);
		else if (strcmp(names[mid], key) < 0)
			finish = mid - 1;
		else
			start = mid + 1;
	}
	return(-1);
}

int shiftDown(char names[][MAX], char added[], int size) 
{
	int i = size;

	do
	{
		i--;
        strcpy(names[i + 1], names[i]);
	}while (strcmp(names[i], added) > 0);
	
    return(i);
}

void addToList(char names[][MAX], char added[], int size)
{
	int index = shiftDown(names, added, size);
	strcpy(names[index], added);
}
