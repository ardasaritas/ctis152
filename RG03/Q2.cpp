#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_string.h"

int main(void)
{
    FILE *in = fopen("words.bin","rb");
    if (in == NULL)
        printf("Error has occured when opening the input file.\n");
    else
    {
        stackk_t s;
        initializeS(&s);

        fseek(in, 0, SEEK_END); 
        int size = ftell(in) / sizeof(char); 

        rewind(in);

        char **Ap; 
        Ap = (char **)malloc(sizeof(char *) * 15);

        for (int r = 0; r < 15; r++)
            *(Ap + r) = (char *)malloc(sizeof(char *) * 15); 
        
        int r = 0;
        while (fread(Ap[r], sizeof(char) * 15, 1, in) > 0)
            r++;

 
        for (int j = 0; j < r; j++)
            if (strlen(Ap[j]) > 5)
                push(&s, Ap[j]);

        printf("Words in Reverse Order\n");
        printf("**********************\n");
        while(!isEmptyS(&s))
        {
            printf("%s\n", pop(&s));
        }
    }
    fclose(in);
    return 0;
}