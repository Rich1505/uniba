#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define POSTI 15
#define N 10


// @brief  Attentionze definire la struttura prima dei prototipi delle funzioni che la utilizzano
//struct Prenotazione per soluzione esercizi 3 e 4
typedef struct {
    int codice;
    char nominativo[100];
    int carrozza;
    int posto;
    float costo;
} Prenotazione;

//Prototipo funzione esercizio 1
void analisiStringa(char stringa[], char parolaLunga[], char parolaCorta[]);
// Prototipo funzione esercizio 2
int gestisciPrenotazione(int treno[], int scelta, int *postiOccupati);
// Prototipi funzioni esercizi 3 e 4
void stampaPrenotazioni(Prenotazione arr[], int n);
void ordina(Prenotazione arr[], int n);
//Prototipo funzioni esercizio 4
void trovaMassimoMinimo(Prenotazione arr[], int n, int *indiceMax, int *indiceMin);
void stampaPrenotazione(Prenotazione p);



int main(){

    /**********************  Esercizio uno ****************/
    char stringa[300];
    char parolaLunga[50];
    char parolaCorta[50];

    printf("Inserisci una stringa:\n");
    fgets(stringa, sizeof(stringa), stdin);
    stringa[strcspn(stringa, "\n")] = '\0';

    analisiStringa(stringa, parolaLunga, parolaCorta);

    printf("Parola più lunga: %s\n", parolaLunga);
    printf("Parola più corta: %s\n", parolaCorta);

    /**********************  Fine Esercizio uno ****************/


    /**********************  Esercizio due ****************/
    int treno[POSTI] = {0};
    int postiOccupati = 0;
    int scelta;

    srand(time(NULL));

    while (postiOccupati < 12) {
        printf("\nScegli la classe:\n1 - Prima classe\n2 - Seconda classe\n");
        scanf("%d", &scelta);

        if (gestisciPrenotazione(treno, scelta, &postiOccupati)) {
            // Posto assegnato con successo
             printf("Posti occupati: %d / 15\n", postiOccupati);
        } else {
            // Prenotazione non effettuata
            printf("Prenotazione non effettuata al prossimo viaggio.\n");
        }   
       
    }

    printf("\nIl treno parte!\n");

    /**********************  Fine Esercizio due ****************/


    /* Struct Prenoatazione inizializzata per Esercizio tre e 4 */
    Prenotazione prenotazioni[N] = {
    {1, "Mario Rossi", 1, 5, 25.5},
    {2, "Luigi Bianchi", 2, 3, 30.0},
    {3, "Anna Verdi", 1, 2, 20.0},
    {4, "Carla Neri", 3, 1, 40.0},
    {5, "Paolo Gialli", 2, 6, 15.0},
    {6, "Laura Blu", 1, 7, 22.5},
    {7, "Francesco Viola", 3, 4, 35.0},
    {8, "Elena Arancio", 2, 8, 28.0},
    {9, "Giovanni Marrone", 3, 9, 18.0},
    {10, "Sara Rosa", 1, 10, 32.0}
    };

    /***** Esercizio 3 *************/
    ordina(prenotazioni, N);

    printf("Array di prenotazioni ordinato per costo:\n");
    stampaPrenotazioni(prenotazioni, N);


    /**************+ Esercizio 4 ********/
    int indiceMax, indiceMin;


    trovaMassimoMinimo(prenotazioni, N, &indiceMax, &indiceMin);

    printf("Prenotazione più costosa:\n");
    stampaPrenotazione(prenotazioni[indiceMax]);

    printf("Prenotazione meno costosa:\n");
    stampaPrenotazione(prenotazioni[indiceMin]);

    return 0;
}


/***  Funzione per esercizio 1*/
void analisiStringa(char stringa[], char parolaLunga[], char parolaCorta[]) {
    int i = 0, j;
    int lunghezza;
    int max = 0;
    int min = 1000;
    char parola[50];
    parolaLunga[0] = '\0';
    parolaCorta[0] = '\0';

    while (stringa[i] != '\0') {

        // Salta gli spazi
        while (isspace(stringa[i])) {
            i++;
        }

        // Costruzione della parola e conteggio caratteri
        j = 0;
        lunghezza = 0;
        while (stringa[i] != '\0' && !isspace(stringa[i])) {
            parola[j++] = stringa[i++];
            lunghezza++;
        }
        parola[j] = '\0';

        // Aggiornamento parola lunga e corta
        if (lunghezza > 0) {
            if (lunghezza > max) {
                max = lunghezza;
                // non è possibile usare parolaLunga = parola;
                parolaLunga=parola;
                //strcpy(parolaLunga, parola);
            }
            if (lunghezza < min) {
                min = lunghezza;
                strcpy(parolaCorta, parola);
            }
        }
    }
}


// Funzione che gestisce l’assegnazione del posto in base alla scelta
// ritorna 1 se assegnato correttamente, 0 se non è stato possibile
int gestisciPrenotazione(int treno[], int scelta, int *postiOccupati) {
    int posto;
    int postiPrima = 0, postiSeconda = 0;

    // Conta posti liberi
    for (int i = 0; i < POSTI; i++) {
        if (treno[i] == 0) {
            if (i < 5) postiPrima++;
            else postiSeconda++;
        }
    }

    if (scelta == 1) { // Prima classe
        if (postiPrima > 0) {
            // Assegna posto casuale in prima classe
            do {
                posto = rand() % 5;
            } while (treno[posto] == 1);

            treno[posto] = 1;
            (*postiOccupati)++;
            printf("Posto assegnato in prima classe: %d\n", posto + 1);
            return 1;
        } else if (postiSeconda > 0) {
            int cambio;
            printf("Prima classe piena. Vuoi un posto in seconda classe? (1 = sì, 0 = no): ");
            scanf("%d", &cambio);
            if (cambio == 1) {
                do {
                    posto = rand() % 10 + 5;
                } while (treno[posto] == 1);

                treno[posto] = 1;
                (*postiOccupati)++;
                printf("Posto assegnato in seconda classe: %d\n", posto + 1);
                return 1;
            } else {
                printf("Nessun posto assegnato.\n");
                return 0;
            }
        } else {
            printf("Mi dispiace, nessun posto libero.\n");
            return 0;
        }

    } else if (scelta == 2) { // Seconda classe
        if (postiSeconda > 0) {
            do {
                posto = rand() % 10 + 5;
            } while (treno[posto] == 1);

            treno[posto] = 1;
            (*postiOccupati)++;
            printf("Posto assegnato in seconda classe: %d\n", posto + 1);
            return 1;
        } else if (postiPrima > 3) {
            int cambio;
            printf("Seconda classe piena. Vuoi un posto in prima classe al prezzo della seconda? (1 = sì, 0 = no): ");
            scanf("%d", &cambio);
            if (cambio == 1) {
                do {
                    posto = rand() % 5;
                } while (treno[posto] == 1);

                treno[posto] = 1;
                (*postiOccupati)++;
                printf("Posto assegnato in prima classe: %d\n", posto + 1);
                return 1;
            } else {
                printf("Nessun posto assegnato.\n");
                return 0;
            }
        } else {
            printf("Mi dispiace, nessun posto libero per la seconda classe.\n");
            return 0;
        }

    } else {
        printf("Scelta non valida.\n");
        return 0;
    }
}


// Funzione per stampare l'array di prenotazioni
void stampaPrenotazioni(Prenotazione arr[], int n) {
    printf("\nCodice\tNominativo\tCarrozza\tPosto\tCosto\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t\t%d\t%.2f\n",
               arr[i].codice, arr[i].nominativo, arr[i].carrozza, arr[i].posto, arr[i].costo);
    }
}

// Funzione che ordina le prenotazioni per costo crescente (bubble sort)
void ordina(Prenotazione arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].costo > arr[j + 1].costo) {
                Prenotazione temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


// Funzione che calcola gli indici della prenotazione più costosa e meno costosa
void trovaMassimoMinimo(Prenotazione arr[], int n, int *indiceMax, int *indiceMin) {
    *indiceMax = 0;
    *indiceMin = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i].costo > arr[*indiceMax].costo) {
            *indiceMax = i;
        }
        if (arr[i].costo < arr[*indiceMin].costo) {
            *indiceMin = i;
        }
    }
}


// Funzione per stampare una prenotazione
void stampaPrenotazione(Prenotazione p) {
    printf("Codice: %d\n", p.codice);
    printf("Nominativo: %s\n", p.nominativo);
    printf("Carrozza: %d\n", p.carrozza);
    printf("Posto: %d\n", p.posto);
    printf("Costo: %.2f\n", p.costo);
    printf("----------------------\n");
}