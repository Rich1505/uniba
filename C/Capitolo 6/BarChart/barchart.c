#include<stdio.h>
#define SIZE 5

int main()
{
    int punteggi[SIZE] = {19,3,15,7,11};

    printf("%-10s%-10s%-20s\n","Index","Value","Barchart");

    for(size_t i = 0;i<SIZE;i++)
    {
        printf("%-10zu%-10d",i,punteggi[i]);
        for(size_t j = 0;j<punteggi[i];j++)
        {
            printf("%c",'*');
        }
        printf("\n");
    }
}