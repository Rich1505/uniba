#include"ordinamento.h"

void swapStudente(Studente **a, Studente **b)
{
    Studente *temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(Studente *vettore[],size_t dimensione)
{   
    size_t min = 0;
    for(size_t i = 0;i<dimensione-1;i++)
    {
        min = i;
        for(size_t j = i+1;j<dimensione;j++)
        {
            if(getEta(vettore[j]) < getEta(vettore[min]))
                min = j;
        }
        if(min != i)
            swapStudente(&vettore[i],&vettore[min]);
    }
}