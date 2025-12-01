#include<stdio.h>

void hearRate(const int eta, int *max_frequenza, int *min_ideale, int *max_ideale)
{
    *max_frequenza = 220-eta;

    *min_ideale = *max_frequenza * 50 / 100;
    *max_ideale = *max_frequenza * 85 / 100;
}

int main()
{
    int eta;
    printf("Inserisci la tua eta:");
    scanf("%d",&eta);

    int max_frequenza,min_ideale,max_ideale;
    hearRate(eta,&max_frequenza,&min_ideale,&max_ideale);

    printf("Frequenza massima: %d\nMinima ideale: %d\nMassima ideale:%d",max_frequenza,min_ideale,max_ideale);
}