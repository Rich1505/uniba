#include<stdio.h>
#include<stdbool.h>

void riempiArray(int[],size_t);
void stampaArray(const int[],size_t);
void bubbleSort(int[],size_t);
int binarySearchRecursive(int[],size_t,size_t,int);
int binarySearchIterative(int[],size_t,int);

int main()
{
    int arr[5];
    riempiArray(arr,sizeof(arr)/sizeof(int));
    stampaArray(arr,sizeof(arr)/sizeof(int));
    bubbleSort(arr,sizeof(arr)/sizeof(int));
    stampaArray(arr,sizeof(arr)/sizeof(int));
    printf("\n%d",binarySearchRecursive(arr,0,sizeof(arr)/sizeof(int),3));
}

void riempiArray(int arr[], size_t size)
{
    for(size_t i = 0;i<size;i++)
    {
        printf("Inserisci elemento %zu: ",i);
        scanf("%d", &arr[i]);
    }
}

void stampaArray(const int arr[], size_t size)
{
    for(size_t i = 0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//costo = (n-1)^2 in tutti i casi, migliore,peggiore,medio
void bubbleSort(int arr[],size_t size)
{
    bool swapped = true;
    int numConfronti = 0;
    for(size_t i = 0;i<size && swapped;i++)
    {
        swapped = false;
        for(size_t j = 1;j<size-i;j++)
        {
            //operazione dominante
            if(arr[j-1] > arr[j])
            {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
            numConfronti++;
        }
    }

    printf("%d\n",numConfronti);
}

int binarySearchRecursive(int arr[],size_t start,size_t end,int find)
{
    if(start > end)
        return -1;

    size_t median = start + (end - start)/2;
    if(arr[median] == find)
        return median;
        
    if(arr[median] > find)
    {
        return binarySearchRecursive(arr,start,median-1,find);
    }
    else
    {
        return binarySearchRecursive(arr,median+1,end,find);
    }
}

int binarySearchIterative(int arr[],size_t size,int find)
{
    size_t start = 0;
    size_t end = size-1;

    while(end >= start)
    {
        int median = start + (end - start)/2;
        if(arr[median] == find)
            return median;

        if(arr[median] > find)
        {
            end = median-1;
        }
        else
        {
            start = median+1;
        }
    }

    return -1;
}