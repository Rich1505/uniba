#include"insertion.h"

void insertionSort(int vettore[], size_t dimensione, int(*op)(int,int))
{
    for(size_t i = 1; i < dimensione; i++)
    {
        int key = vettore[i];
        size_t j = i;

        while(j > 0 && op(vettore[j - 1], key) == 1)
        {
            vettore[j] = vettore[j - 1];
            j--;
        }
        vettore[j] = key;
    }
}

int ascending(int a,int b)
{
    if(a > b)
        return 1;
    else
        return 0;
}

int descending(int a,int b)
{
    if(a < b)
        return 1;
    else
        return 0;
}