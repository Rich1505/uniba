#include"ordinamento.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int vettore[],size_t dimensione)
{   
    size_t min = 0;
    for(size_t i = 0;i<dimensione-1;i++)
    {
        min = i;
        for(size_t j = i+1;j<dimensione;j++)
        {
            if(vettore[j] < vettore[min])
                min = j;
        }
        if(min != i)
            swap(&vettore[i],&vettore[min]);
    }
}