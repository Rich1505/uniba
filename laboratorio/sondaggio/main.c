#include<stdio.h>
#define N 20

int main()
{
    int voti[N] = {0};

    int frequenzaVoti[5] = {0};
    
    for(int i = 0;i < N;i++)
    {
        printf("Inserisci voto %d da 1 a 5: ", i + 1);

        while(scanf("%d", &voti[i]) != 1 || (voti[i] > 5 || voti[i] <= 0))
        {
            printf("%d\n", voti[i]);
            printf("Inserisci un voto valido tra 1 e 5: ");
            while(getchar() != '\n')
            {
                ;
            }

        }

        frequenzaVoti[voti[i]-1]++;
    }

    for(int i = 0;i < 5;i++)
    {
        printf("Frequenza di %d: %d\n",i+1,frequenzaVoti[i]);
    }
}