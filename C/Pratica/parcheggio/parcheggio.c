#include<stdio.h>
#include<math.h>
#define NUM_CLIENTI 3

void caricaOre(float[]);
void calcolaCosti(float[],float[]);
void stampaCosti(float[],float[]);

int main()
{
    float ore[NUM_CLIENTI];
    float costi[NUM_CLIENTI];

    caricaOre(ore);
    calcolaCosti(ore,costi);
    stampaCosti(ore,costi);
}

void caricaOre(float ore[])
{
    for(int i = 0;i<NUM_CLIENTI;i++)
    {
        printf("Inserisci orario %d: ",i+1);
        scanf("%f",&ore[i]);

        while(ore[i] < 0 || ore[i] > 24)
        {
            printf("Inserisci orario %d: ",i+1);
            scanf("%f",&ore[i]);
        }
    }
}

void calcolaCosti(float ore[],float costi[])
{
    for(int i = 0;i<NUM_CLIENTI;i++)
    {
        if(ore[i] <= 3)
        {
            costi[i] = 2.0f;
        }
        else
        {
            costi[i] = 2.0f + ceil(ore[i]-3.0f)*0.5f;
            costi[i] = fmin(costi[i],10.0f);
        }
    }
}

void stampaCosti(float ore[],float costi[])
{
    printf("%-20s %-8s %10s\n", "Cliente","Ore","Costo");
    for(int i = 0;i<NUM_CLIENTI;i++)
    {
        printf("%-20d %-8.2f %10.2f\n",i,ore[i],costi[i]);
    }
}