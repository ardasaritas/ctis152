#include <stdio.h>
#include <stdlib.h>


#define LENGTH 20

typedef struct
{
	char name[20]; 
	double price;
	int discountRate; 
} amazon_t;

int main(void)
{
	FILE *in = fopen("amazon.txt", "r"); 

	if (in == NULL)
		printf("Error!\n");
	else
	{
		int flag;
		fscanf(in, "%d", &flag);
		
		amazon_t *matrix;
		matrix = (amazon_t *)malloc(sizeof(amazon_t)*flag);

        int i = 0;

	    while ((fscanf(in, "%s %lf %d", ((matrix + i)->name), &((matrix + i)->price), &((matrix + i)->discountRate)) != EOF) && i < flag)
            i++;

		printf("There are %d products in the market\n\n", i);
		printf("PRODUCT NAME       PRICE     DISCOUNT  DISC. PRICE   SAVED AMOUNT\n");
		printf("************       ********  ********  ***********   ************\n");

        double discAmount, savedAmount;

		for (int r = 0; r < i; r++)
		{
            discAmount = (matrix + r)->price * (matrix + r)->discountRate / 100.0;
			printf("%-17s %7.2f $       %%%-5d %7.2f $ %12.2f $\n", (matrix + r)->name, (matrix + r)->price, (matrix + r)->discountRate, (matrix + r)->price - discAmount, discAmount);
        }	

		fclose(in);
		free(matrix);
	}
}