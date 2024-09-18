/****
Simple monitoring software for a library, reads from "books.txt",
at most 7 books are allowed. 
*****/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 7 

typedef struct 
{
    int bookID;
    char bookName[50];
    double bookPrice;
}book_t;

// Displays the menu, validates choice 
void dispMenu(int *choice); 

// Reads the books' information to a specified structure array
int readFile(FILE *in, book_t arr[]); 

// Adds a new record if library is not full
int newRecord(book_t arr[], int size);

// Displays the library
void display(book_t arr[], int size); 

int main(void)
{
    FILE *in = fopen("books.txt","r"); 

    if (in == NULL)
        printf("Error has occured when opening file.\n"); 
    else
    {
        int choice, actSize; 

        book_t *arr; 
        arr = (book_t *)malloc(sizeof(book_t) * MAXSIZE); 

        actSize = readFile(in, arr);

        dispMenu(&choice);
        while (choice != 3) // Automatically exists when choice = 3
        {
            switch(choice)
            {
                case 1: 
                display(arr, actSize);
                break; 

                case 2: 
                if (newRecord(arr, actSize))
                {   
                    printf("\nNew record successfully added.\n\n"); 
                    actSize++;
                } 
                else
                    printf("The library is full.\n\n");  
            }
            dispMenu(&choice);
        }
        return(0); 
    }
}

void dispMenu(int *choice)
{
    printf("1. Display the current library\n"); 
    printf("2. Add new book to the library\n"); 
    printf("3. Exit\n\n"); 

    printf("Enter your choice: "); 
    scanf("%d", choice); 

    while((*choice) > 3 || (*choice) < 1)
    {
        printf("Please re-enter your choice: "); 
        scanf("%d", choice); 
    }
}

int readFile(FILE *in, book_t arr[])
{
    int count = 0;

    while(fscanf(in,"%d %s %lf", &(arr + count)->bookID, (arr + count)->bookName, &(arr + count)->bookPrice) != EOF && (count < MAXSIZE))
        count++;
    
    return(count); 
}

int newRecord(book_t arr[], int size)
{
    if (size >= MAXSIZE) // Checks if library is full
        return(0); 
    else
    {
        int index, temp; 
        printf("Please enter new book info:\n\n");
        printf("Enter book ID: "); 
        
        // Searches for the first blank to fill 
        for (int r = size; r >= 0; r--)
            if(strcmp((arr + r)->bookName, "\0") == 0)
                index = r;
        scanf("%d", &(arr + index)->bookID); 

        printf("Enter book name: "); 
        scanf(" %[^\n]", (arr + index)->bookName); 

        printf("Enter book price: "); 
        scanf("%lf", &(arr + index)->bookPrice); 

        return(1); 
    }
}

void display(book_t arr[], int size)
{
    printf("Current library\n");
    printf("***************\n\n");
    for (int r = 0; r < size; r++)
        printf("ID: %d\nName: %s\nPrice: %0.2f $\n\n", (arr + r)->bookID, (arr + r)->bookName, (arr + r)->bookPrice);     
}