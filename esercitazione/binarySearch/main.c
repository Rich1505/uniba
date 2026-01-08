#include<stdio.h>
#include"binarySearch.h"

int main()
{
    int arr[] = {3,5,7};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    printf("%zu", binarySearch(arr,size,7));
}