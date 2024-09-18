#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char name[30]; 
    double uPrice; 
    int quantity;
} product_t;

void readFromFile(FILE *in, product_t *products, int numOfProducts);

void display(product_t *products, int numOfProducts); 

int menu(product_t *products, int numOfProducts); 

int main(void)
{
    FILE *in = fopen("products.txt","r"); 
    
    if (in == NULL)
        printf("Error has occured when opening file.\n"); 
    else
    {
        int choice, flag, productCount = 0;
        double money, paymentCount = 0.0; 

        fscanf(in,"%d", &flag);

        product_t *products; 
        products = (product_t *)malloc(sizeof(product_t) * flag);
        
        readFromFile(in, products, flag); 

        choice = menu(products, flag); 

        while (choice != -1)
        {
            if ((products + choice)->quantity > 0)
            {
                printf("Insert money to purchase: ");
                scanf("%lf", &money);

                if (money >= (products + choice)->uPrice)
                {
                    printf("%0.2f TL returned back.\n", money - (products + choice)->uPrice);
                    (products + choice)->quantity--;
                    productCount++; 
                    paymentCount += money - money - (products + choice)->uPrice; 
                }
                
                else printf("Your money is not enough, returned back.\n");
            }    
            else printf("There is no more %s\n", (products + choice)->name);

            choice = menu(products, flag);
        }
        printf("******************************************\n");
        printf("%d products sold today.\n", productCount); 
        printf("Total received payment is: %0.2f TL\n\n", -paymentCount); 
       
        fclose(in);
        free (products); 
    }
    return(0); 
}

void readFromFile(FILE *in, product_t *products, int numOfProducts)
{
    int i = 0; 
    
    while (fscanf(in," %[^0-9] %lf %d", (products + i)->name, &((products + i)->uPrice), &((products + i)->quantity)) != EOF && (i < numOfProducts))
        i++;
        
}

void display(product_t *products, int numOfProducts)
{  
    for (int r = 0; r < numOfProducts; r++)
    {
        if((products + r)->quantity == 0)
            printf("%2d. %-15s      %0.2f            OUT\n", r + 1, (products + r)->name, (products + r)->uPrice);
        else 
        printf("%2d. %-15s      %0.2f            %3d\n", r + 1, (products + r)->name, (products + r)->uPrice, (products + r)->quantity);
    }
        
    printf("\n");
}

int menu(product_t *products, int numOfProducts)
{
   
    int choice;
    printf("\n    PRODUCT           UNIT PRICE      QUANTITY\n");
    display(products, numOfProducts);
    
    printf("Enter the product number (to stop -1): "); 
    scanf("%d", &choice);
   
    if (choice != -1)
        return(choice - 1);
    else return(choice);
}