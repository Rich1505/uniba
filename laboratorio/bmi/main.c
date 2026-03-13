#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N_PERSONE 10

int main()
{
    srand(time(NULL));

    float maxPesoOver40 = -1;
    float maxPesoUnder40 = -1;
    float maxAltezzaOver40 = -1;
    float maxAltezzaUnder40 = -1;
    float sumBMI = 0;

    for(int i = 0;i < N_PERSONE;i++)
    {
        float peso = rand() % 500 + 1;
        float altezza = (rand() % 300 + 20) / 100.0f;
        int eta = rand() % 120 + 1;
        
        float BMI = peso / (altezza * altezza);

        sumBMI += BMI;
        printf("Persona %d:\nEta: %d\nPeso: %.2f\nAltezza: %.2fm\nBMI: %.2f\n------------------\n",i+1,eta,peso,altezza,BMI);
    }

    float mediaBMI = mediaBMI / N_PERSONE;
}