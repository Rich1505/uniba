#include <stdio.h>
#define MAX_CARATTERI 10

int main()
{
    char nome[MAX_CARATTERI];
    char cognome[MAX_CARATTERI];
    int eta;
    int scelta = 0;

    const char nomeFile[30] = "./dati.txt";
    FILE *f = fopen(nomeFile, "w");

    if (f != NULL)
    {
        while (scelta != -1)
        {
            printf("Inserire nome cognome eta: ");
            scanf("%s %s %d", nome, cognome, &eta);

            fprintf(f, "%s %s %d\n", nome, cognome, eta);
            // fflush(f)
            printf("Continuare? -1 per uscire:");
            scanf("%d", &scelta);
        }
        fclose(f);
    }
    else
    {
        perror("Errore di accesso al file");
    }

    f = fopen(nomeFile,"r");
    if(f != NULL)
    {
        char riga[50];
        while(fgets(riga,sizeof(riga),f) != NULL)
        {
            printf("%s",riga);
        }

        fclose(f);
    }
    else
    {
        perror("Errore nell'apertura del file");
    }

    // ACCODATI NEL FILE
    //f = fopen("./dati.txt","a");


    // PER RIPORTARE IL CURSORE ALL'INIZIO DEL FILE
    //rewind(f);


    // PER SCRIVERE FILE BINARI
    //f = fopen("./dati.txt","wb");

    return 0;
}