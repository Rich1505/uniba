#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50

typedef struct dataDiNascita{
    int giorno;
    int mese;
    int anno;
} DataDiNascita;

typedef struct studente{
    char nome[MAX];
    char cognome[MAX];
    char matricola[7];
    DataDiNascita data_di_nascita;
    int esami[20];
} Studente;

void inputStudenti(Studente *studenti, size_t size)
{
    for(size_t i = 0;i < size;i++)
    {
        char nome[MAX];
        char cognome[MAX];
        char matricola[7];
        int giorno;
        int mese;
        int anno;

        printf("Studente %zu\n", i + 1);
        printf("Inserisci nome: ");
        scanf("%49s", nome);
        printf("\nInserisci cognome: ");
        scanf("%49s", cognome);
        printf("\nInserisci matricola: ");
        scanf("%6s", matricola);

        printf("\nInserisci giorno-mese-anno di nascita: ");
        scanf("%d-%d-%d", &giorno, &mese, &anno);
        strcpy(studenti[i].nome, nome);
        strcpy(studenti[i].cognome, cognome);
        strcpy(studenti[i].matricola, matricola);
        studenti[i].data_di_nascita.giorno = giorno;
        studenti[i].data_di_nascita.mese = mese;
        studenti[1].data_di_nascita.anno = anno;
        
        for(size_t j = 0; j < 20;j++)
        {
            int voto = rand() % 32;
            studenti[i].esami[j] = voto;
        }

    }
}

void stampaDati(Studente *studenti, size_t size)
{
    int modaVoti[32] = {0};
    float maxMedia = -1;
    size_t indexMaxMedia = -1;
    for(size_t i = 0;i < size;i++)
    {
        float somma = 0;
        for(size_t j = 0;j < 20;j++)
        {
            somma += studenti[i].esami[j];
            modaVoti[studenti[i].esami[j]]++;
        }

        float media = somma/20.0f;
        if(media > maxMedia)
        {
            maxMedia = media;
            indexMaxMedia = i;
        }

        printf("Media studente %zu: %.2f\n", i+1, media);
    }

    printf("\nStudente con media piu alta: %s %s\n", studenti[indexMaxMedia].nome, studenti[indexMaxMedia].cognome);

    int maxModa = -1;
    int maxApparizioni = -1;
    for(size_t i = 0;i < 32;i++)
    {
        if(modaVoti[i] > maxApparizioni)
        {
            maxModa = i;
            maxApparizioni = modaVoti[i];
        }
    }
    printf("Moda voto: %d\n", maxModa);
}

int main()
{
    srand(time(NULL));

    Studente studenti[10];
    inputStudenti(studenti, sizeof(studenti)/sizeof(Studente));
    stampaDati(studenti, sizeof(studenti)/sizeof(Studente));
    
    return 0;
}