#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct studente{
    char *nome;
    char *cognome;
    int eta;
};

int main()
{
    char nome[15] = "Riccardo";
    char cognome[15] = "Pistillo";
    struct studente *s;
    s = malloc(sizeof(struct studente));

    if(s == NULL)
    {
        perror("errore nella creazione dell'istanza");
        return -1;
    }
    
    s->nome = malloc(sizeof(char) * (strlen(nome) + 1));

    if(s->nome == NULL)
    {
        perror("Errore nell'allocazione");
        return -1;
    }

    strcpy(s->nome,nome);

    s->cognome = malloc(sizeof(char)*(strlen(cognome)+1));

    if(s->cognome == NULL)
    {
        perror("Errore nell'allocazione");
        return -1;
    }

    strcpy(s->cognome,cognome);

    printf("%s %s %d",s->nome,s->cognome,s->eta);

    free(s->nome);
    free(s->cognome);
    free(s);
    s = NULL;
}