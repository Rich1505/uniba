#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

typedef struct prenotazione
{
    int codice;
    char nominativo[100];
    int numeroCarrozza;
    int numeroPosto;
    float costoBiglietto;
} Prenotazione;

void analisiStringa(char stringa[], char parolaLunga[], char parolaCorta[]);
int gestisciPrenotazione(int treno[], int scelta, int *postiOccupati);
void bubbleSort(Prenotazione prenotazioni[], size_t size);
void printPrenotazioni(Prenotazione prenotazioni[], size_t size);

int main()
{
    srand(time(NULL));
    //esercizio 1
    char str[100];
    char parolaLunga[100];
    char parolaCorta[100];
    printf("Inserisci stringa: ");
    fgets(str,99,stdin);
    analisiStringa(str,parolaLunga,parolaCorta);
    printf("Parola piu lunga: %s\nParola piu corta: %s\n",parolaLunga,parolaCorta);

    //esercizio 2
    int treno[15] = {0};
    int postiOccupati = 0;
    while(postiOccupati < 12)
    {
        int scelta = 0;
        printf("Inserisci scelta:\n1_Prima classe\n2_Seconda classe\n");
        scanf("%d", &scelta);
        while(scelta < 1 || scelta > 2)
        {
            printf("Scelta non valida\n");
            scanf("%d",&scelta);
        }

        if(gestisciPrenotazione(treno,scelta,&postiOccupati))
        {
            printf("Prenotazione effettuata, posti occupati: %d\n",postiOccupati);
        }
        else
        {
            printf("Prenotazione non effettuata\n");
        }
    }

    //esercizio 3
    Prenotazione prenotazioni[] = {{0,"Riccardo",0,0,0.0f},{1,"Fabio",1,1,5.0f},{2,"Lorenzo",2,2,3.0f},{3,"Francesco",3,3,7.0f},{4,"Luca",4,4,9.0f},{5,"Mattia",5,5,12.0f},{6,"Vittorio",6,6,4.0f},{7,"Caterino",7,7,7.5f},{8,"Gianfranco",8,8,8.0f},{9,"Claudio",9,9,4.5f}};
    printPrenotazioni(prenotazioni,sizeof(prenotazioni)/sizeof(prenotazioni[0]));
    printf("\n\n");
    bubbleSort(prenotazioni,sizeof(prenotazioni)/sizeof(prenotazioni[0]));
    printPrenotazioni(prenotazioni,sizeof(prenotazioni)/sizeof(prenotazioni[0]));

    //esercizio 4
    Prenotazione prenotazioneMin = prenotazioni[0];
    Prenotazione prenotazioneMax = prenotazioni[9];
    printf("Prenotazione costo minore: %d %s %d %d %.2f\n",prenotazioneMin.codice,prenotazioneMin.nominativo,prenotazioneMin.numeroCarrozza,prenotazioneMin.numeroPosto,prenotazioneMin.costoBiglietto);
    printf("Prenotazione costo maggiore: %d %s %d %d %.2f\n",prenotazioneMax.codice,prenotazioneMax.nominativo,prenotazioneMax.numeroCarrozza,prenotazioneMax.numeroPosto,prenotazioneMax.costoBiglietto);
}

void printPrenotazioni(Prenotazione prenotazioni[], size_t size)
{
    for(size_t i = 0;i<size;i++)
    {
        printf("%d %s %d %d %.2f\n",prenotazioni[i].codice,prenotazioni[i].nominativo,prenotazioni[i].numeroCarrozza,prenotazioni[i].numeroPosto,prenotazioni[i].costoBiglietto);
    }
}

/**
 * 
 * Ordinamento esercizio 3
 */
void bubbleSort(Prenotazione prenotazioni[], size_t size)
{
    bool swapped = true;
    for(size_t i = 0;i<size-1 && swapped;i++)
    {
        swapped = false;
        for(size_t j = 0;j < size - i - 1;j++)
        {
            if(prenotazioni[j].costoBiglietto > prenotazioni[j+1].costoBiglietto)
            {
                Prenotazione temp = prenotazioni[j];
                prenotazioni[j] = prenotazioni[j+1];
                prenotazioni[j+1] = temp;
                swapped = true;
            }
        }
    }
}

/**
 * Funzione che gestisce prenotazioni
 * esercizio 2
 */
int gestisciPrenotazione(int treno[], int scelta, int *postiOccupati)
{
    int postiPrimaClasse = 0;
    int postiSecondaClasse = 0;
    for(int i = 0;i<5;i++)
    {
        if(treno[i] == 0)
        postiPrimaClasse++;
    }

    for(int i = 5;i<15;i++)
    {
        if(treno[i] == 0)
        postiSecondaClasse++;
    }

    if(scelta == 1)
    {
        if(postiPrimaClasse > 0)
        {
            int random = 0;
            do
            {
                random = rand() % 5;
            }while(treno[random] == 1);

            treno[random] = 1;
            *postiOccupati = *postiOccupati + 1;
            printf("Posto occupato: %d\n",random);
            return 1;
        }
        else
        {
            int choice = 0;
            printf("Non ci sono posti in prima classe, vuole un posto in seconda classe?\n1_si\n2_no\n");
            scanf("%d", &choice);

            while(choice < 1 || choice > 2)
            {
                printf("Scelta non valida\n");
                scanf("%d", &choice);
            }

            if(choice == 1)
            {
                int random = 0;
                do
                {
                    random = rand() % 10 + 5;
                }while(treno[random] == 1);

                treno[random] = 1;
                *postiOccupati = *postiOccupati + 1;
                printf("Posto occupato: %d\n",random);
                return 1;
            }
            else
            {
                printf("Mi dispiace nessun posto libero per la prima classe\n");
                return 0;
            }
        }
    }
    else
    {
        if(postiSecondaClasse > 0)
        {
            int random = 0;
            do
            {
                random = rand() % 10 + 5;
            }while(treno[random] == 1);

            treno[random] = 1;
            *postiOccupati = *postiOccupati + 1;
            printf("Posto occupato: %d\n",random);
            return 1;
        }
        else if(postiPrimaClasse > 3)
        {
            int choice = 0;
            printf("Non ci sono posti in seconda classe, vuole un posto in prima classe al costo della seconda classe=?\n1_si\n2_no\n");
            scanf("%d", &choice);

            while(choice < 1 || choice > 2)
            {
                printf("Scelta non valida\n");
                scanf("%d", &choice);
            }

            if(choice == 1)
            {
                int random = 0;
                do
                {
                    random = rand() % 5;
                }while(treno[random] == 1);
                treno[random] = 1;
                *postiOccupati = *postiOccupati + 1;
                printf("Posto occupato: %d\n",random);
                return 1;
            }
            else
            {
                printf("Mi dispiace i posti per la seconda classe sono terminati\n");
                return 0;
            }
        }
        else
        {
            printf("Mi dispiace i posti per la seconda classe sono terminati\n");
            return 0;
        }
    }
}

/**
 * 
 * Funzione che calcola la parola più lunga e più corta
 * Esercizio 1
 */
void analisiStringa(char stringa[], char parolaLunga[], char parolaCorta[])
{
    int i = 0;
    int lunghezzaMax = 0;
    int lunghezzaMin = 100;
    char inspectedString[100];
    while(stringa[i] != '\0')
    {   
        int j = 0;
        while(!isspace(stringa[i + j]) && stringa[i + j] != '\0')
        {
            inspectedString[j] = stringa[i + j];
            j++;
        }
        inspectedString[j] = '\0';

        if(j)
        {
            if(strlen(inspectedString) > lunghezzaMax)
            {
                lunghezzaMax = strlen(inspectedString);
                strcpy(parolaLunga,inspectedString);
            }

            if(strlen(inspectedString) < lunghezzaMin)
            {
                lunghezzaMin = strlen(inspectedString);
                strcpy(parolaCorta,inspectedString);
            }
            strcpy(inspectedString,"");
            i += j;
        }
        else
        {
            i++;
        }
    }
}

