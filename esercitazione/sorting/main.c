#include<stdio.h>
#include"sorting.h"

void printArray(int arr[], size_t size)
{
    for(size_t i = 0;i < size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {45,34,2134,52,234,23523,4234,132,365,58,123};
    printArray(arr,sizeof(arr)/sizeof(arr[0]));
    insertionSort(arr,sizeof(arr)/sizeof(arr[0]),ascending);
    printArray(arr,sizeof(arr)/sizeof(arr[0]));
}