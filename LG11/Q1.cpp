#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int readFile(FILE *in, int arr[]); 

int binarySearch(int arr[], int start, int finish, int key, int *count); 

int main(void)
{
    FILE *in = fopen("empIDs.txt","r"); 

    if (in == NULL)
        printf("Error has occured when opening the input file.\n"); 
    else
    {
        int idArr[MAX], key, comparisonCount = 0, index; 
        int actSize = readFile(in, idArr); 

        printf("Enter value to find: "); 
        scanf("%d", &key); 

        index = binarySearch(idArr, 0, actSize - 1, key, &comparisonCount); 

        if (index == -1)
            printf("The number is not in the empIDS.txt\n");
        else        
            printf("%d is found at %d. line\n", key, index + 1);
        
        printf("%d comparisons.\n", comparisonCount);
    }
    return(0); 
}

int readFile(FILE *in, int arr[])
{
    int count = 0; 
    while(fscanf(in,"%d", &arr[count]) != EOF && (count < MAX))
        count++;
    return(count);
}

int binarySearch(int arr[], int start, int finish, int key, int *count)
{
    int mid; 

    while (start <= finish)
    {
        mid = (start + finish) / 2;
        
        if (arr[mid] == key)
        {
            (*count)++;
            return(mid);             
        }
        else if (arr[mid] > key)
        {
            (*count)++;
            finish = mid - 1;  
        }    
        else 
        {
            (*count)++;
            start = mid + 1;
        }                
    }
    return(-1); 
}