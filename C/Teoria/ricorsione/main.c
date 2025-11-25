#include<stdio.h>
#include"myMath.h"

int main()
{
    int a;
    printf("Inserisci il numero di cui calcolare Fibonacci: ");
    scanf("%d",&a);

    printf("Fibonacci di %d: %lld",a,fibonacci(a));
}