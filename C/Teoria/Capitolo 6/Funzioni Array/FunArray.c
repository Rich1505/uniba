#include<stdio.h>

int max(int[],size_t);

int main()
{
    int size = 9;
    int arr[] = {1,2,3,4,5,6,7,8,9};

    printf("Max: %d\n",max(arr,sizeof(arr)/sizeof(int)));
    return 0;
}


/**
 * 
 * @brief Seleziona il valore più grande
 * @param arr L'array in cui cercare il massimo
 * @param size La dimensione del vettore
 * @return il valore più grande; -1 se non è stato possibile individuarlo
 * 
 */
int max(int arr[], size_t size)
{
    if(size > 0)
    {
        int max = arr[0];
        for(size_t i = 1;i<size;i++)
        {
            if(arr[i] > max)
            max = arr[i];
        }
        return max;
    }
    return -1;
    
}