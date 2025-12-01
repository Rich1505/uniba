#include<stdio.h>
#define MAX 20
#define INTERVAL 100-10+1

int duplicato(int n,int num[])
{
    return num[n-10];
}

int main()
{
    int arr[MAX] = {0};
    int interval[INTERVAL] = {0};

    int count = 0;
    int n = 0;
    for(int i = 0;i<MAX;i++)
    {
        printf("Inserisci un numero compreso tra 10 e 100(numero %d): ",i);
        scanf("%d",&n);

        while(n < 10 || n > 100)
        {
            printf("Inserire un numero valido: ");
            scanf("%d",&n);
        }

        if(!duplicato(n,interval))
        {
            arr[count] = n;
            count++;
            interval[n-10] = 1;
        }

    }

    for(int i = 0;i<count;i++)
    {
        printf("%d ",arr[i]);
    }
}