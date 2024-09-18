// Reverses the digits of randomly generated numbers 
// Writes them into the file "reverse.txt"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Finds the digits of given number and assignes them into an array
void findDigits(int array[], int number);

int main(void)
{
    // Defining file pointer
    FILE* out = fopen("reverse.txt","w");

    // File corruption check 
    if (out == NULL)
        printf("Error occured when opening file.");
    
    else
    {
        int num, generated, digitArr[3]; 

        // Prompting the user for count of numbers to be generated
        printf("How many numbers will you generate? ");
        scanf("%d", &num);


        fprintf(out,"Generated number    Digits in reverse order\n");
        fprintf(out,"****************    ***********************\n");

        srand(time(0));

        /* Generates random number, writes the number itself, 
        then writes the digits in reverse order */
        for (int i = 0; i < num; i++)
        {
        generated = rand () % (900) + 100;
        findDigits(digitArr, generated);
        fprintf(out, "%16d", generated);

        for (int k = 0; k < 3; k++)
            fprintf(out, "%7d ", digitArr[k]);

        fprintf(out, "\n");
        }
        
        fclose(out);
    }
    return (0);
}

void findDigits(int array[], int number)
{
    int count = 0; 

    while (number != 0)
    {
        array[count++] = number % 10; 
        number/=10;
    }
}