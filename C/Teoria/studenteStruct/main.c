#include<stdio.h>
#include"studente.h"
#include"ordinamento.h"

int main()
{
    Studente *s = creaStudente(5,"CIAOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
    printStudente(s);
    rimuoviStudente(s);
    
    int n = 0;
    printf("Numero studenti: ");
    scanf("%d",&n);

    Studente *studenti[n];

    for(size_t i = 0;i<n;i++)
    {
        int eta;
        char buffer[255];
        char *nome;
        printf("Studente %zu:\n",i);
        printf("Inserisci eta: ");
        scanf("%d",&eta);
        printf("Inserisci nome:");
        scanf("%254s",buffer);
        studenti[i] = creaStudente(eta,buffer);
    }

    for(size_t i = 0;i<n;i++)
    {
        printStudente(studenti[i]);
    }

    selectionSort(studenti,n);
    puts("");
    
    for(size_t i = 0;i<n;i++)
    {
        printStudente(studenti[i]);
    }
}