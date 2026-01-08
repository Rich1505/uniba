#include"sorting.h"

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool ascending(int a,int b)
{
    return a > b;
}

bool descending(int a,int b)
{
    return a < b;
}

void bubbleSort(int *arr, size_t size, bool (*op)(int,int))
{
    bool swapped = true;
    for(size_t i = 0;i < size-1 && swapped;i++)
    {
        swapped = false;
        for(size_t j = 0;j < size - i - 1;j++)
        {
            if(op(arr[j],arr[j + 1]))
            {
                swapped = true;
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int *arr, size_t size, bool (*op)(int,int))
{
    for(size_t i = 0;i < size - 1;i++)
    {
        size_t key = i;
        for(size_t j = i + 1;j < size;j++)
        {
            if(op(arr[key],arr[j]))
            {
                key = j;
            }
        }
        if(key != i)
            swap(&arr[i], &arr[key]);
    }
}

void insertionSort(int arr[], size_t n, bool (*op)(int,int))
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && op(arr[j],key)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}