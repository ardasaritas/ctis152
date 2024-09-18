#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack_string.h"

int main(void)
{
    FILE *in = fopen("sentences.bin","rb");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        char *str = (char *)malloc(sizeof(char) * 100);
        stackk_t s;
        initializeS(&s); 
    
        int ptr = 0;
        while(fread(str, sizeof(char), 100, in) > 0)
        {
            int len = strlen(str);
            while (str[ptr] != '\0' && ptr < len)
            {   
                char temp[100] = ""; 
                while (!isblank(str[ptr]) && str[ptr] != '\0')
                {
                    strncat(temp, str + ptr, 1);
                    ptr++;
                }
                push(&s, temp);
                ptr++;
            }
            printf("\nThe original sentence is: %s\nReverse of the sentence is: ", str); 
            while (!isEmptyS(&s))
                printf("%s ", pop(&s));
            printf("\n");
    
            ptr = 0;
        }
        printf("\n");
        free(str); 
        fclose(in);
    }
    return(0);
}