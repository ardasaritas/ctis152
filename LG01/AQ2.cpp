// Prints a menu and does what is says :)
#include <stdio.h>

int menu(void);

// Initializez an array of 25 all 0
void initializeArray(int array[]);

// Fills an array until the user enters sentinel value (0)
void inArray(int array[], int *length);

// Prints out the array
void outArray(int array[], int length);

// Finds a certain key's position (index) in an array and returns it
int findPos(int array[], int length, int key);

int main(void)
{
    int array[25], length = 0, key, res;

    res = menu();
    do
    {
        switch(res)
        {
        case 1: 
        initializeArray(array);
        break;

        case 2:
        printf("Enter the elements of the array sets: \n");
        inArray(array, &length);
        break;

        case 3: 
        outArray(array, length);
        break;

        case 4: 
        printf("Enter the value that will be searched: ");
        scanf("%d", &key);
        
        if (findPos(array, length, key) != -1)
        printf("Position of the value is: %d\n", findPos(array, length, key));    
        else 
        printf("Not a match!\n");
        break;
            
        default: 
        printf("Please enter a valid choice. ");
        }
    
    res = menu();
    }while (res != 5); // 5 is the exit choice
return(0);
}

int menu(void)
{
    int choice;
    printf("\n\n       MENU\n1. Initialize Array\n2. Input Array Elements\n3. Output Array Elements\n4. Search a value\n5. Exit the program\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    return(choice);
}
void initializeArray(int array[])
{
    for (int i = 0; i < 25; i++)
        array[i] = 0;
}

void inArray(int array[], int *length)
{
    scanf("%d", &array[(*length)]);
    while (array[(*length)] != 0)
    {
        (*length)++;
        scanf("%d", &array[(*length)]);
    }
    printf("The size of array is %d\n", (*length));
}

void outArray(int array[], int length)
{
    for(int i = 0; i < length; i++)
        printf("%d ", array[i]);
}

int findPos(int array[], int length, int key)
{
    for (int i = 0; i < length; i++)
        if (array[i] == key)
            return(i); 
    return (-1);
}