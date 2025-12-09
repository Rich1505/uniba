#include "studente.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct studente
{
    int eta;
    char *nome;
};

Studente *creaStudente(int eta, char *nome)
{
    Studente *s = malloc(sizeof(Studente));

    if (s != NULL)
    {

        if(nome != NULL)
        {
            size_t nameSize = strlen(nome) + 1;
            s->nome = malloc(nameSize * sizeof(char));
            if(s->nome != NULL)
                strcpy(s->nome, nome);
        }

        s->eta = eta;
    }
}

int getEta(const Studente *s)
{
    return s->eta;
}

char *nome(const Studente *s)
{
    return s->nome;
}

void setEta(Studente *s, int eta)
{
    s->eta = eta;
}

void setNome(Studente *s, char *nome)
{
    free(s->nome);
    size_t nameSize = strlen(nome) + 1;
    s->nome = malloc(nameSize);
    strcpy(s->nome, nome);
}

void rimuoviStudente(Studente *s)
{
    if(s != NULL)
    {
        if(s->nome != NULL)
        {
            free(s->nome);
        }
        free(s);
    }
}

void printStudente(Studente *s)
{
    printf("Nome: %s\nEta: %d\n", s->nome, s->eta);
}