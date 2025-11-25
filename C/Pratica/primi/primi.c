#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10000

void inizializza(int *array)
{
    for(int i = 0;i<MAX;i++)
    {
        array[i] = (i%2 == 0) ? 0 : 1;
    }
}

int* eratostene(int *array)
{
    array[0] = array[1] = 0;
    array[2] = 1;

    int c = 3;
    while(c * c < MAX)
    {
        if(array[c])
        {
            int d = c*2;
            while(d <= MAX)
            {
                array[d] = 0;
                d+=c;
            }
        }

        c+=2;
    }

    return array;
}

void stampaPrimi(int *array)
{   
    int count = 0;
    for(int i = 2;i<MAX;i++)
    {
        if(array[i])
        {
            printf("%d ",i);
            count++;
        }
    }
    printf("\nNumeri trovati:%d\n",count);
}

int main()
{
    clock_t start = clock();

    int numbers[MAX];
    inizializza(numbers);
    eratostene(numbers);
    stampaPrimi(numbers);
    

    double time = ((double) (clock() - start)) / CLOCKS_PER_SEC;

    printf("Tempo:%f",time);

}