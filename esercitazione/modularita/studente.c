#include"studente.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct studente{
    char *nome;
    int eta;
};

int a = 5;

Studente *creaStudente(char nome[], int eta)
{
    Studente *s = malloc(sizeof(Studente));
    if(s != NULL)
    {
        s->nome = malloc(strlen(nome) + 1);
        if(s->nome != NULL)
        {
            strcpy(s->nome,nome);
            s->eta = eta;
            return s;
        }
        free(s);
    }
    return NULL;
}

void distruggiStudente(Studente *s)
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

const char *getNome(const Studente *s)
{
    return s->nome;
}

int getEta(const Studente *s)
{
    return s->eta;
}

void setNome(Studente *const s, const char nome[])
{
    if(s->nome != NULL)
    {
        free(s->nome);
    }

    s->nome = malloc(strlen(nome) + 1);
    if(s->nome != NULL)
        strcpy(s->nome,nome);
}

void setEta(Studente *const s, const int eta)
{
    s->eta = eta;
}

void printStudente(const Studente *const s)
{
    printf("%s %d\n",s->nome,s->eta);
}

//const si applica prima a quello che sta a sinistra, se non c'è niente si applica a destra