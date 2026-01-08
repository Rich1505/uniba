#include<stdio.h>
#include"studente.h"

int main()
{
    char nome[100] = "";
    int eta;

    printf("Inserisci nome: ");
    scanf("%99s",nome);
    printf("Inserisci eta: ");
    scanf("%d",&eta);

    Studente *s = creaStudente(nome,eta);

    printStudente(s);

    printf("%s\n",getNome(s));
    setNome(s,"Carletto");
    printf("%s\n", getNome(s));
    printf("%d",a);
    distruggiStudente(s);
}