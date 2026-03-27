#include<stdio.h>
#define MAX 50
#define NUM_CATEGORIE 4
#define NUM_GIORNI 5

void input_prodotti(int prodotti[NUM_GIORNI][NUM_CATEGORIE], char categorie[NUM_CATEGORIE][MAX])
{
    for(size_t i = 0;i < NUM_GIORNI;i++)
    {
        printf("Giorno %zu:\n", i+1);
        for(size_t j = 0;j < NUM_CATEGORIE;j++)
        {
            printf("Inserisci i prodotti della categoria %s: ", categorie[j]);

            while(scanf("%d", &prodotti[i][j]) != 1)
            {
                while(getchar() != '\n')
                {
                    ;
                }

                printf("Inserisci un valore valido: ");
            }
        }
    }
}

void stampa_info(int prodotti[NUM_GIORNI][NUM_CATEGORIE], char categorie[NUM_CATEGORIE][MAX])
{
    int totale_categorie[NUM_CATEGORIE] = {0};
    int totale = 0;

    int maxGiorno = -1;
    int maxProdotti = -1;
    for(size_t i = 0;i < NUM_GIORNI;i++)
    {
        int totale_giornaliero = 0;
        for(size_t j = 0;j < NUM_CATEGORIE;j++)
        {
            totale_giornaliero += prodotti[i][j];
            totale_categorie[j] += prodotti[i][j];
        }

        printf("Totale giorno %zu: %d\n", i+1, totale_giornaliero);
        totale += totale_giornaliero;
        
        if(totale_giornaliero > maxProdotti)
        {
            maxProdotti = totale_giornaliero;
            maxGiorno = i;
        }
    }

    printf("Totale della settimana: %d\n", totale);
    int maxCategoria = -1;
    int maxProdottiCategoria = -1;
    for(size_t i = 0;i < NUM_CATEGORIE;i++)
    {
        printf("Totale categoria %s: %d\n", categorie[i], totale_categorie[i]);
        if(totale_categorie[i] > maxProdottiCategoria)
        {
            maxProdottiCategoria = totale_categorie[i];
            maxCategoria = i;
        }
    }

    printf("Categoria con piu' prodotti venduti: %s con %d prodotti venduti\n", categorie[maxCategoria], totale_categorie[maxCategoria]);
}

int main()
{
    char categorie[NUM_CATEGORIE][MAX] = {"Alimentari", "Cancelleria", "Elettronica", "Casa"};

    int prodotti_venduti[NUM_GIORNI][NUM_CATEGORIE] = {0};
    input_prodotti(prodotti_venduti, categorie);
    stampa_info(prodotti_venduti, categorie);

}