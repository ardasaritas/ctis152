/*****
Reads information about books from a file into a dynamically created array.
Program displays the book information and the total price of each one.
*******/ 
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int bookID;
    char bookType;
    double bookPrice;
}book_t;

// Reads the books' information from the file into the two-dim array
void readFromFile(FILE *in, book_t *infoBooks, int numOfBooks);

// Calculates the total prices of text and reference books than displays all the information
void displayAndCalculate(book_t *infoBooks, int numOfBooks);

int main(void)
{
    FILE *in = fopen("books.txt","r");

    if (in == NULL)
        printf("Error has occured when opening file.\n");
    else
    {
        int numOfBooks;
        fscanf(in,"%d", &numOfBooks);
        
        book_t *infoBooks; 
        infoBooks = (book_t *)malloc(sizeof(book_t) * numOfBooks); 

        readFromFile(in, infoBooks, numOfBooks); 
        displayAndCalculate(infoBooks, numOfBooks); 

        fclose(in); 
        free(infoBooks);
    }
    return (0); 
}

void readFromFile(FILE *in, book_t *infoBooks, int numOfBooks)
{
    int count = 0; 

    while((fscanf(in, "%d %s %lf", &((infoBooks + count)->bookID), &((infoBooks + count)->bookType), &((infoBooks + count)->bookPrice)) != EOF) && count < numOfBooks)
        count++; 
}

void displayAndCalculate(book_t *infoBooks, int numOfBooks)
{
    double sumT= 0, sumR = 0; 

    printf("     Information of Books\n"); 
    printf("  ID        TYPE          Price\n");
    printf("*********************************\n");
    
    for (int i = 0; i < numOfBooks; i++)
    {
        printf("%5d", (infoBooks + i) -> bookID); 
        if ((infoBooks + i) -> bookType == 'T')
        {
            sumT += (infoBooks + i) ->bookPrice;
            printf("   Textbook          "); 
        }
            
        else if ((infoBooks + i) -> bookType == 'R')
        {
            sumR += (infoBooks + i) ->bookPrice;
            printf("   Reference Book    "); 
        }
        else printf("  INVALID          "); 
        printf("%6.2f\n", (infoBooks + i) -> bookPrice); 
    }   
    printf("\nTotal price of the Textbooks -> %0.2f $\n", sumT); 
    printf("Total price of the Textbooks -> %0.2f $\n\n", sumR); 
}