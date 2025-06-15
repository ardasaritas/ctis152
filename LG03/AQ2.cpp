#include <stdio.h>
#include <stdlib.h>

int dispMenu();

void readFile(FILE *in, int idArr[], double balanceArr[]);

int displayZeroBalances(double balanceArr[], int length, int zeroBalanceArr[]);


int findMaxBalance(double balanceArr[], int length);


int main(void)
{
    FILE *in = fopen("customers.txt","r");

    if (in == NULL)
        printf("Error has occured when opening input file.\n");
    else
    {
        int i = 0, length, count, maxIndex; 

        fscanf(in,"%d", &length);

        int *id;
        id = (int *) malloc(sizeof(int) * length);

        double *balance; 
        balance = (double *) malloc(sizeof(double) * length);

        int *zerobalance;
        zerobalance = (int *) malloc(sizeof(int) * length);
        
        readFile(in, id, balance);

        int flag = dispMenu();

        while (flag != 3)
        {
            switch (flag)
            {
            case 1: 
            count = displayZeroBalances(balance, length, zerobalance);
            printf("Account with zero balances:\n");
            for (int i = 0; i < count; i++)
                printf("%d\n", *(id + (*(zerobalance) + i)));
            break;

            case 2: 
            maxIndex = findMaxBalance(balance, length);
            printf("\nAccount info which has the maximum balance:\nID: %d Balance: %0.2f\n\n", *(id + maxIndex), *(balance + maxIndex));
            break;
            }
            flag = dispMenu();
        }
    fclose(in);
    }
return (0);
}

int dispMenu()
{
    int choice;

    printf("                MENU                \n");
    printf("------------------------------------\n");
    printf("1- List the accounts with zero balances\n");
    printf("2- Display the account which has the maximum balance\n");
    printf("3- Exit\n");
    
    printf("Enter your request (1, 2, 3): "); 
    scanf("%d", &choice);

    while (choice > 3 || choice < 1)
    {
        printf("Please enter a valid request index (1, 2, 3): ");
        scanf("%d", &choice);
    }
    return(choice);
}

void readFile(FILE *in, int idArr[], double balanceArr[])
{
    int count = 0; 

    while(fscanf(in, "%d %lf", idArr + count, balanceArr + count)!= EOF)
        count++;
}

int displayZeroBalances(double balanceArr[], int length, int zeroBalanceArr[])
{
    int i, k = 0; 

    for (i = 0; i  < length; i++)
        if (*(balanceArr + i) == 0.00)
            *(zeroBalanceArr + k++) = i;
    return(k);
}

int findMaxBalance(double balanceArr[], int length)
{
    int i, max = *balanceArr, maxIndex; 

    for (i = 1; i < length; i++)
        if (*(balanceArr + i) > max)
        {
            max = *(balanceArr + i);
            maxIndex = i;
        }    
            

    return (maxIndex);
}