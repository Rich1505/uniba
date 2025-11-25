#include"studente.h"
#include<stdlib.h>
#include<string.h>

struct studente{
    char *nome;
    char *cognome;
    int eta;
};


/**
 * 
 * @brief Costruisce un'istanza di Studente
 * @return istanza di Studente, NULL altrimenti
 */
Studente* creaStudente(const char* nome,const char* cognome, int eta)
{
    Studente *s = malloc(sizeof(Studente));
    if(s == NULL)
        return NULL;

    s->nome = malloc(strlen(nome)+1);
    if(s->nome == NULL)
    {
        free(s);
        return NULL;
    }

    s->cognome = malloc(strlen(cognome)+1);
    if(s->cognome == NULL)
    {
        free(s->nome);
        free(s);
        return NULL;
    }

    strcpy(s->nome,nome);
    strcpy(s->cognome,cognome);
    s->eta = eta;

    return s;
}

void distruggiStudente(Studente* s)
{
    free(s->nome);
    free(s->cognome);
    free(s);
    s = NULL;
}

const char* getNome(const Studente* s)
{
    char *str = malloc(strlen(s->nome)+1);
    strcpy(str,s->nome);
    return str;
}

const char* getCognome(const Studente* s)
{
    char *str = malloc(strlen(s->cognome)+1);
    strcpy(str,s->cognome);
    return str;
}

int getEta(const Studente* s)
{
    return s->eta;
}