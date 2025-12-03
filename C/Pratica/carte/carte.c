#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SEMI 4
#define VALORI 12
int main()
{
    srand(time(NULL));

    char semi[5] = {'c','q','f','p'};
    int inHand[SEMI][VALORI] = {0};


    int n = 0;
    printf("Inserisci le carte per mano:");
    scanf("%d",&n);

    while(n <= 0)
    {
        printf("Inserisci un valore valido: ");
        scanf("%d",&n);
    }


    char hand[n][4];
    for(int i = 0;i<n;i++)
    {
        int seme = 0;
        int valore = 0;
        do
        {
            seme = rand() % 4;
            valore = (rand() % 12) + 1;
        }while(inHand[seme][valore-1]);

        inHand[seme][valore-1] = 1;
        hand[i][0] = semi[seme];
        
        char str_aux[3];
        _itoa_s(valore,str_aux,3,10);
        hand[i][1] = str_aux[0];
        hand[i][2] = (valore > 10) ? str_aux[1] : '\0';
        hand[i][3] = '\0';
    }

    printf("La tua mano e': ");
    for(int i = 0;i<n;i++)
    {
        printf("%s ",hand[i]);
    }
}