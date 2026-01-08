#include"binarySearch.h"

size_t binarySearch(int arr[], size_t size, int n)
{
    size_t low = 0;
    size_t high = size - 1;
    size_t med = 0;

    while(high >= low)
    {
        med = low + (high - low)/2;
        if(arr[med] == n)
        {
            return med;
        }
        else if(arr[med] > n)
        {
            high = med - 1;
        }
        else
        {
            low = med + 1;
        }
    }
    return -1;
}