#include <stdio.h>

void inizializzaVettore(int *, size_t, int);
void popolaArray(int *, size_t);

static const int MAX_STUDENTI = 5;
static const int MIN_STUDENTI = 1;
static const int MIN_VOTO = 1;
static const int MAX_VOTO = 10;

int main()
{
    int voti[MAX_STUDENTI];
    const char file[15] = "./voti.dat";
    int valoreLetto = -1;

    // 1.inizializzazione vettore voti
    size_t dimensione = sizeof(voti) / sizeof(voti[0]);
    inizializzaVettore(voti, dimensione, -1);

    // 2.Popolare vettore voti
    popolaArray(voti, dimensione);

    // 3.Memorizzare i voti su file
    FILE *filePtr = fopen(file, "wb");

    if (filePtr != NULL)
    {
        fwrite(voti, sizeof(voti[0]), dimensione, filePtr);
        fclose(filePtr);
    }
    else
    {
        perror("Errore creazione file");
    }

    // 4.Lettura dei valori
    filePtr = fopen(file, "rb");

    if (filePtr != NULL)
    {
        if (fread(&valoreLetto, sizeof(valoreLetto), 1, filePtr) == 1)
            printf("Valore letto: %d\n", valoreLetto);

        fclose(filePtr);
    }
    else
    {
        perror("Errore in lettura");
    }

    // 5.Ricerca di un valore specificata la posizione
    filePtr = fopen(file, "rb");
    int posizione = -1;

    if (filePtr != NULL)
    {
        printf("Posizione da leggere: ");
        scanf("%d", &posizione);

        // può essere negativo per andare indietro
        long offset = sizeof(int) * (long)(posizione - 1);
        fseek(filePtr, offset, SEEK_SET);
        if (fread(&valoreLetto, sizeof(int), 1, filePtr) == 1)
            printf("Valore letto: %d\n", valoreLetto);

        fclose(filePtr);
    }
    else
    {
        perror("Errore nella lettura");
    }

    // 6.Modificare valore specificando posizione e nuovo valore
    filePtr = fopen(file,"rb+");
    int valoreDaScrivere = -1;

    if(filePtr != NULL)
    {
        printf("Posizione da scrivere: ");
        scanf("%d", &posizione);

        printf("Valore da scrivere: ");
        scanf("%d",&valoreDaScrivere);

        long offset = sizeof(int) * (long)(posizione - 1);
        fseek(filePtr,offset,SEEK_SET);
        fwrite(&valoreDaScrivere,sizeof(valoreDaScrivere),1,filePtr);

        rewind(filePtr);
        fseek(filePtr,offset,SEEK_SET);
        if(fread(&valoreLetto,sizeof(valoreLetto),1,filePtr) == 1)
            printf("Valore scritto: %d\n",valoreLetto);

        fclose(filePtr);
    }
    else
    {
        perror("Errore nella lettura");
    }
}

void inizializzaVettore(int *vettore, size_t dimensione, int valIniziale)
{
    for (size_t i = 0; i < dimensione; i++)
    {
        vettore[i] = valIniziale;
    }
}

void popolaArray(int *vettore, size_t dimensione)
{

    int valore = -1;
    for (size_t i = 0; i < dimensione; i++)
    {
        printf("Inserisci voto: ");
        scanf("%d", &valore);
        while (valore < MIN_VOTO || valore > MAX_VOTO)
        {
            printf("Inserisci voto: ");
            scanf("%d", &valore);
        }
        vettore[i] = valore;
    }
}