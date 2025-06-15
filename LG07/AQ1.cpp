#include <stdio.h>
#include <string.h>


int main(void)
{
    FILE *in = fopen("input.txt","r"); 
    FILE *out = fopen("output.txt","w"); 

    if (in == NULL)
        printf("Error has occured when opening file.\n"); 
    else
    {
        char temp[50][20];  
        int r = 0, wordLengths[50], occurences[50] = {0};

        // Scanning the words' lengths directly into an array called wordLengths
        while (fscanf(in,"%s", *(temp + r)) != EOF)    
        {
           wordLengths[r] = strlen(*(temp + r)); 
           r++;
        }
        // Increases occurrences[word length] one by one (for instance: if we have 3 words with length of 5, occurences[5] will be 3)
        for (int i = 0; i < r; i++)
            occurences[wordLengths[i]]++;
        
        fprintf(out, "Word Length     Occurrences\n");
        fprintf(out, "----------------------------\n");

        /* Checks lengths that have occured, if it didn't occur even once, both the occurences and the counts will not be displayed
        as occurence will be 0 and occurence[?] will be a garbage value. If it occured, the length and the occurence count will be displayed
        */ 
        for (int j = 0; j < r; j++)
            if (occurences[j] != 0)
                fprintf(out, "   %2d               %d\n", j, occurences[j]); 
        
        fclose(in); 
        fclose(out);
    }
    return(0);
}