#ifndef STUDENTE_H
#define STUDENTE_H

typedef struct studente Studente;

//Costruttore del tipo studente
Studente *creaStudente(const char*,const char*,int);

//Distruttore di studente
void distruggiStudente(Studente*);

//Deve restituire una deep copy
const char* getNome(const Studente*);
const char* getCognome(const Studente*);
int getEta(const Studente*);

// void setNome(Studente*,char*);
// void setCognome(Studente*,char*);
// void setEta(Studente*,int);


#endif