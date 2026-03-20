#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TRIES 10

typedef enum stato{
    VUOTO,
    NAVE,
    INDOVINATO
} Stato;

int main()
{
    srand(time(NULL));

    int points = 0;

    Stato tabella[6][6] = {VUOTO};
    for(int i = 0;i < 6;i++)
    {
        int riga = rand() % 6;
        int colonna = rand() % 6;
        while(tabella[riga][colonna] == NAVE)
        {
            riga = rand() % 6;
            colonna = rand() % 6;
        }

        tabella[riga][colonna] = NAVE;
    }

    for(int i = 0;i < TRIES; i++)
    {
        printf("Hai ancora %d tentativi per indovinare\n", TRIES - i);

        printf("Inserisci riga(A-F) e colonna(1-6): ");

        char riga = 0;
        int colonna = 0;

        int valid = scanf("%c %d", &riga, &colonna);

        while(riga < 'A' || riga > 'F' || colonna < 1 || colonna > 6 || valid != 2)
        {
            while(getchar() != '\n')
            {
                ;
            }
            
            printf("Inserisci valori validi\n");
            valid = scanf("%c %d", &riga, &colonna);
        }

        getchar();

        riga = riga - 'A';
        if(tabella[riga][colonna] == VUOTO)
        {
            printf("Hai sbagliato!\n");
        }
        else if(tabella[riga][colonna] == NAVE)
        {
            printf("Nave affondata\n");
            tabella[riga][colonna] = INDOVINATO;
            points++;
        }
        else
        {
            printf("Hai già indovinato questa nave\n");
            i--;
        }
    }

    printf("Hai totalizzato %d punti\n", points);


}