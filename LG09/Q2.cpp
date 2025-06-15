#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char ext[5]; 
	char description[50];
}ext_t;

int readFile(FILE *in, ext_t *extens);

int search(ext_t *extens, char *sent, int size);

int main(void)
{
	FILE *in = fopen("extensions.txt", "r"); 

	if (in == NULL)
		printf("Error has occured when opening file.\n");
	else
	{
		ext_t *extens;
		extens = (ext_t *)malloc(sizeof(ext_t) * 20); 

		char URL[50]; 
    
		int actsize = readFile(in, extens);
		fclose(in);

		printf("Enter a website URL: "); 
		scanf("%[^\n]", &URL); 

		int index = search(extens, URL, actsize); 

		if (index == -1)
			printf("The searched URL's extension is not in the list.\n");
		else
			printf("%s extension is used for %s\n", (extens + index)->ext, (extens + index)->description); 
	}
    return(0);
}

int readFile(FILE *in, ext_t *extens)
{
	int count = 0; 

	while (fscanf(in, "%s %[^\n]", (extens + count)->ext, (extens + count)->description) != EOF)
		count++; 
	
	return(count);
}

int search(ext_t *extens, char *sent, int size)
{
	int sentLen = strlen(sent); 
	int index = -1; 

	for (int k = sentLen - 4; k >= 0; k--)
		for (int i = 0; i < size; i++)
			if (strncmp(sent + k, (extens + i)->ext, strlen((extens + i)->ext)) == 0)
			{
				index = i;
				return(index);
			}
	return(index);
}
