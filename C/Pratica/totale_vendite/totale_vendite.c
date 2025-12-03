#include<stdio.h>
#define VENDITORI 4
#define PRODOTTI 5

void cacca(size_t r,size_t j, int arr[r][j])
{
    
}

void leggiProdotti(float prodotti[VENDITORI][PRODOTTI])
{
    int n = 0;
    while(n != -1)
    {
        int venditore = 0;
        int prodotto = 0;
        float valore = 0.f;
        printf("Inserisci venditore(1-4), prodotto(1-5) e valore: ");
        scanf("%d %d %f",&venditore,&prodotto,&valore);
        
        while(venditore < 1 || venditore > 4 || prodotto < 1 || prodotto > 5 || valore < 0.0f)
        {
            printf("Inserisci valori validi:");
            scanf("%d %d %f",&venditore,&prodotto,&valore);
        }

        prodotti[venditore-1][prodotto-1] += valore;

        printf("-1 per terminare:");
        scanf("%d",&n);
    }
}

void calcolaTotaleRighe(float prodotti[VENDITORI][PRODOTTI],float righe[VENDITORI])
{
    for(size_t i = 0;i<VENDITORI;i++)
    {
        float totale = 0.f;
        for(size_t j = 0; j < PRODOTTI;j++)
        {
            totale += prodotti[i][j];
        }
        righe[i] = totale;
    }
}

void calcolaTotaleColonne(float prodotti[VENDITORI][PRODOTTI], float colonne[PRODOTTI])
{
    for(size_t i = 0;i<PRODOTTI;i++)
    {
        float totale = 0.f;
        for(size_t j = 0;j<VENDITORI;j++)
        {
            totale += prodotti[j][i];
        }
        colonne[i] = totale;
    }
}

void stampa(float prodotti[VENDITORI][PRODOTTI], float righe[VENDITORI], float colonne[PRODOTTI])
{
    printf("%10s","Venditori");
    for(size_t i = 0;i<PRODOTTI;i++)
    {
        printf("%10s","");
    }
    printf("%10s","Totale");
    printf("\n");

    for(size_t i = 0;i<VENDITORI;i++)
    {
        printf("%10zu",i+1);
        for(size_t j = 0;j<PRODOTTI;j++)
        {
            printf("%10.2f",prodotti[i][j]);
        }
        printf("%10.2f\n",righe[i]);
    }

    printf("%10s","Totale");
    for(size_t i = 0;i<PRODOTTI;i++)
    {
        printf("%10.2f",colonne[i]);
    }
}

int main()
{
    float prodotti[VENDITORI][PRODOTTI] = {0.0f};

    leggiProdotti(prodotti);

    float totaliRighe[VENDITORI] = {0.0f};
    float totaliColonne[PRODOTTI] = {0.0f};

    calcolaTotaleRighe(prodotti,totaliRighe);
    calcolaTotaleColonne(prodotti,totaliColonne);
    stampa(prodotti,totaliRighe,totaliColonne);


}