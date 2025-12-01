#include<stdio.h>
#include<stdlib.h>

void invertiVettore(int v[],int n);
void stampaVettore(int v[],int n);
void leggiVettore(int v[],int n);

int main()
{
    int n = 0;
    printf("Inserisci grandezza vettore:");
    scanf("%d",&n);

    int *v = malloc(n*sizeof(int));
    leggiVettore(v,n);
    stampaVettore(v,n);
    invertiVettore(v,n);
    stampaVettore(v,n);

    return 0;
}

void leggiVettore(int v[],int n)
{
    for(int i = 0;i<n;i++)
    {
        printf("Inserisci valore %d:",i);
        scanf("%d",&v[i]);
    }
}

void invertiVettore(int v[],int n)
{
    for(int i = 0;i<n/2;i++)
    {
        int temp = v[i];
        v[i] = v[n-i-1];
        v[n-i-1] = temp;
    }
}

void stampaVettore(int v[],int n)
{
    for(int i = 0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
}