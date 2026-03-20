#include<stdio.h>
#include<string.h>
#define MAX 50

typedef struct data
{
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct esame
{
    char nome[MAX];
    int voto;
} Esame;

typedef struct studente
{
    char nome[MAX];
    char cognome[MAX];
    Data dataDiNascita;
    Esame esami[2];
} Studente;

int main()
{
    Studente studente1;

    strcpy(studente1.nome, "Riccardo");
    stpcpy(studente1.cognome, "Pistillo");
    studente1.dataDiNascita.giorno = 15;
    studente1.dataDiNascita.mese = 5;
    studente1.dataDiNascita.anno = 2006;
    strcpy(studente1.esami[0].nome, "Programmazione");
    studente1.esami[0].voto = 30;
    strcpy(studente1.esami[1].nome, "Matematica Discreta");
    studente1.esami[1].voto = 30;

    printf("Nome: %s\nCognome:%s\nData di nascita: %d/%d/%d\n-------\nEsame 1:\nNome: %s\nVoto: %d\n---------\nEsame 2:\nNome: %s\nVoto: %d\n",studente1.nome,studente1.cognome,studente1.dataDiNascita.giorno,studente1.dataDiNascita.mese,studente1.dataDiNascita.anno,studente1.esami[0].nome, studente1.esami[0].voto, studente1.esami[1].nome, studente1.esami[1].voto);

}