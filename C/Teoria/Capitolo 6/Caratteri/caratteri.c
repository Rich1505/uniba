#include<stdio.h>
#define SIZE_PAROLA 200
int main()
{
    char parola[SIZE_PAROLA];
    printf("Inserisci valore:");
    scanf("%s",parola);

    printf("\nIndirizzo di memoria: %p\n",parola);
    printf("Indirizzo di memoria %p\n",&parola[0]);

    printf("%s",parola);
    return 0;
}