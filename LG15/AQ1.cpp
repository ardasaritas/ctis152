// Reads a paragraph from a file, reverses every sentence, finds the word with the maximum length
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack_struct2.h"

int main(void)
{
    FILE *in = fopen("input.txt","r");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        char *str = (char *)malloc(sizeof(char) * 100);
        stackk_t s;
        initializeS(&s); 
        int max = 0;
        char maxWord[20] = ""; 

        int ptr = 0;
        while(fscanf(in, " %[^\r]", str) != EOF)
        {
            int len = strlen(str);
            while (str[ptr] != '\0' && ptr < len)
            {   
                word_t temp;
                strcpy(temp.word, "");

                int size = 0;
                while (!isblank(str[ptr]) && str[ptr] != '\0')
                {
                    strncat(temp.word, str + ptr, 1);
                    ptr++;
                    size++;
                }
                temp.length = size; 
                
                if (size > max)
                {
                    max = size; 
                    strcpy(maxWord, temp.word);
                }
                
                push(&s, temp);
                ptr++;
            }
            while (!isEmptyS(&s))
                printf("%s ", pop(&s).word);    
            printf("\n");
            ptr = 0;
        }
        printf("\nThe maximum length word is <%s> and size is %d\n\n", maxWord, max);
        free(str); 
        fclose(in);
    }
    return(0);
}