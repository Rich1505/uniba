#include<stdio.h>
#include"ordinamento.h"

void printValues(int[],size_t);

int main()
{
    int punteggi[] = {2,4,3,8,5,4,4,1,10,6,46,45,45,346,54,4,342,56,568,56,53,234,123,345,65,78,897,45,243,436};
    size_t dimensione = sizeof(punteggi)/sizeof(punteggi[0]);
    printValues(punteggi,dimensione);
    selectionSort(punteggi,dimensione);
    printValues(punteggi,dimensione);
    

    return 0;
}

void printValues(int vettore[],size_t dimensione)
{
    for(size_t i = 0;i<dimensione;i++)
    {
        printf("%d ",vettore[i]);
    }
    printf("\n");
}