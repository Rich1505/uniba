#ifndef STUDENTE_H
#define STUDENTE_H

extern int a;

typedef struct studente Studente;

Studente *creaStudente(char nome[], int eta);
void distruggiStudente(Studente *s);
const char *getNome(const Studente *s);
int getEta(const Studente *s);
void setNome(Studente *const s, const char nome[]);
void setEta(Studente *const s, const int eta);
void printStudente(const Studente const* s);

#endif