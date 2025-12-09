#ifndef STUDENTE_H
#define STUDENTE_H

typedef struct studente Studente;

Studente *creaStudente(int,char*);

int getEta(const Studente*);
char* getNome(const Studente*);

void setEta(Studente*,int);
void setNome(Studente*,char*);

void rimuoviStudente(Studente* s);

void printStudente(Studente *s);

#endif