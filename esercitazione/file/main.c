#include<stdio.h>
#include<stdlib.h>

typedef struct studente{
    char nome[20];
    int eta;
} Studente;

void printStudente(Studente s)
{
    printf("%s %d\n",s.nome,s.eta);
}

int main()
{
    char fileName[] = "studenti.dat";
    int n;
    printf("Inserisci la quantita di studenti: ");
    scanf("%d",&n);

    Studente studenti[n];
    for(size_t i = 0;i<n;i++)
    {
        
        printf("Inserisci nome e eta studente %d: ",i+1);
        scanf("%20s %d",studenti[i].nome,&(studenti[i].eta));
    }


    FILE *file = fopen(fileName,"w+");
    if(file != NULL)
    {
        fwrite(studenti,sizeof(Studente),n,file);

        rewind(file);

        printf("Lettura da file...\n");
        Studente studentiLetti[n];
        fread(studentiLetti,sizeof(Studente),n,file);

        for(size_t i = 0;i<n;i++)
        {
            printStudente(studentiLetti[i]);
        }

        int index = 0;
        printf("Inserisci numero studente da leggere: ");
        scanf("%d",  &index);

        fseek(file,index * sizeof(Studente),SEEK_SET);

        Studente studenteLetto;
        fread(&studenteLetto,sizeof(Studente),1,file);
        printStudente(studenteLetto);

        fclose(file);
    }
}