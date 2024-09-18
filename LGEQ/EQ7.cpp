#include <stdio.h>
#include <stdlib.h>
#include "queue_struct.h"

int main(void)
{
    FILE *in = fopen("customers.bin","rb");
    if (in == NULL)
        printf("Error has occured when opening the file.\n"); 
    else
    {
        queue_t CD1;
        initializeQ(&CD1);

        queue_t CD2;
        initializeQ(&CD2);

        queue_t CD3;
        initializeQ(&CD3);

        int countCash = 0, countVisa = 0;
        double totalPayment = 0.0;
        QType temp;
        rewind(in);
        while(fread(&temp, sizeof(QType), 1, in) > 0)
        {
            switch(temp.code)
            {
                case 'V':
                case 'C':    
                {
                    int array[] = {CD1.counter, CD2.counter, CD3.counter}; 
                    int min = CD1.counter; 
                    int index = 1; 

                    for (int r = 0; r < 3; r++)
                        if (array[r] < min)
                        {
                            min = array[r]; 
                            index = r + 1;
                        }

                    switch(index)
                    {
                        case 1: 
                            insert(&CD1, temp);
                            break;
                        case 2: 
                            insert(&CD2, temp);
                            break;
                        case 3: 
                            insert(&CD3, temp);
                            break;
                    }
                    break;
                }   
                break;
                case 'P':
                {
                    switch((int)temp.amount)
                    {
                        case 1:
                            QType temp2;
                            temp2 = remove(&CD1); 
                            switch(temp2.code)
                            {
                                case 'V':
                                    countVisa++;
                                    totalPayment += temp2.amount;
                                    break;
                                case 'C':
                                    countCash++;
                                    totalPayment += temp2.amount;
                            }
                        break; 

                        case 2:
                            QType temp3;
                            temp3 = remove(&CD2); 
                            switch(temp3.code)
                            {
                                case 'V':
                                    countVisa++;
                                    totalPayment += temp3.amount;
                                    break;
                                case 'C':
                                    countCash++;
                                    totalPayment += temp3.amount;
                            }
                        break; 
                        
                        case 3:
                            QType temp4;
                            temp4 = remove(&CD3); 
                            switch(temp4.code)
                            {
                                case 'V':
                                    countVisa++;
                                    totalPayment += temp4.amount;
                                    break;
                                case 'C':
                                    countCash++;
                                    totalPayment += temp4.amount;
                            }
                        break; 
                    }
                }     
                    break;
            }
        }
        
        printf("Cash Desk 1:\n");
        while(!isEmptyQ(&CD1))
        {
            QType temp5 = remove(&CD1);
            printf("%c %5.2f\n",temp5.code, temp5.amount);
        }
        printf("\n");

        printf("Cash Desk 2:\n");
        while(!isEmptyQ(&CD2))
        {
            QType temp6 = remove(&CD2);
            printf("%c %5.2f\n",temp6.code, temp6.amount);
        }
        printf("\n");

        printf("Cash Desk 3:\n");
        while(!isEmptyQ(&CD3))
        {
            QType temp7 = remove(&CD3);
            printf("%c %5.2f\n",temp7.code, temp7.amount);
        }
        printf("\n");

        printf("Number of cash payments: %d\n", countCash);
        printf("Number of visa payments: %d\n", countVisa);
        printf("Total Payment: %6.2f\n\n", totalPayment);
    }
    fclose(in);
    return(0);
}