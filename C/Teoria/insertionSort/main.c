#include<stdio.h>
#include"insertion.h"
#include<string.h>

void printVettore(int vettore[], size_t dimensione)
{
    for(size_t i = 0; i < dimensione; i++)
    {
        printf("%d ", vettore[i]);
    }
    printf("\n");
}

int main()
{
    int punteggi[] = {2,4,3,8,5,4,4,1,10,6,46,45,45,346,54,4,342,56,568,56,53,234,123,345,65,78,897,45,243,436};

    size_t dimensione = sizeof(punteggi)/sizeof(int);

    printVettore(punteggi, dimensione);

    insertionSort(punteggi, dimensione, descending);

    printVettore(punteggi, dimensione);
    
    return 0;
}