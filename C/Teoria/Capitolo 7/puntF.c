//VERSIONE SENZA PUNTATORI

// #include<stdio.h>

// int scontoBase(int,int);
// int scontoFedelta(int,int);
// int scontoBF(int,int);
// int calcolaCosto(int,int,int);

// int main()
// {

//     int costoBase = 10;
//     int numeroUnita = 5;
//     int tipoSconto = 0;

//     printf("Tipo sconto (1--3): ");
//     scanf("%d",&tipoSconto);

//     while (tipoSconto != -1)
//     {
//         switch(tipoSconto)
//         {
//             case 1:
//                 printf("Costo: %d\n",calcolaCosto(numeroUnita,costoBase,1));
//                 break;

//             case 2:
//                 printf("Costo: %d\n",calcolaCosto(numeroUnita,costoBase,2));
//                 break;

//             case 3:
//                 printf("Costo: %d\n",calcolaCosto(numeroUnita,costoBase,3));
//                 break;

//             default:
//                 break;
//         }

//         printf("Tipo sconto (1--3): ");
//         scanf("%d",&tipoSconto);
//     }
    
// }

// int scontoBase(int numeroUnita, int costoBase)
// {
//     int costo = 0;
//     costo = numeroUnita * costoBase * 0.95;
//     return costo;
// }

// int scontoFedelta(int numeroUnita, int costoBase)
// {
//     int costo = 0;
//     if(numeroUnita > 3)
//         costo = numeroUnita * costoBase * 0.85;
//     else
//         costo = numeroUnita * costoBase * 0.95;

//     return costo;
// }

// int scontoBF(int numeroUnita, int costoBase)
// {
//     int costo = 0;
//     if(numeroUnita > 4)
//     {
//         costo = numeroUnita * costoBase * 0.70;
//     }
//     else
//     {
//         costo = numeroUnita * costoBase * 0.72;
//     }
//     return costo;
// }

// int calcolaCosto(int numeroUnita, int costoBase, int tipoSconto)
// {
//     int costo = 0;
//     if(numeroUnita > 0 && costoBase > 0)
//     {
//         switch (tipoSconto)
//         {
//         case 1:
//             costo = scontoBase(numeroUnita,costoBase);
//             break;
        
//         case 2:
//             costo = scontoFedelta(numeroUnita,costoBase);
//             break;

//         case 3:
//             costo = scontoBF(numeroUnita,costoBase);
//             break;

//         default:
//             break;
//         }
//     }
//     else
//         costo = 0;
    
//     return costo;
// }

// VERSIONE CON PUNTATORI

#include<stdio.h>

int scontoBase(int,int);
int scontoFedelta(int,int);
int scontoBF(int,int);
int calcolaCosto(int,int,int (*strategy)(int,int));

int main()
{

    int costoBase = 10;
    int numeroUnita = 5;
    int tipoSconto = 0;

    //vettore con 3 funzioni
    int (*f[3])(int,int) = {scontoBase,scontoFedelta,scontoBF};

    printf("Tipo sconto (1--3): ");
    scanf("%d",&tipoSconto);

    while (tipoSconto != -1)
    {
        //SENZA ARRAY DI FUNZIONI
        // switch(tipoSconto)
        // {
        //     case 1:
        //         printf("Costo: %d\n",calcolaCosto(numeroUnita,costoBase,scontoBase));
        //         break;

        //     case 2:
        //         printf("Costo: %d\n",calcolaCosto(numeroUnita,costoBase,scontoFedelta));
        //         break;

        //     case 3:
        //         printf("Costo: %d\n",calcolaCosto(numeroUnita,costoBase,scontoBF));
        //         break;

        //     default:
        //         break;
        // }
        
        // CON ARRAY DI FUNZIONI

        if(tipoSconto >= 1 && tipoSconto <= 3)
        {
            printf("costo: %d\n",calcolaCosto(numeroUnita,costoBase,f[tipoSconto-1]));
        }

        printf("Tipo sconto (1--3): ");
        scanf("%d",&tipoSconto);
    }
    return 0;
    
}

int scontoBase(int numeroUnita, int costoBase)
{
    int costo = 0;
    costo = numeroUnita * costoBase * 0.95;
    return costo;
}

int scontoFedelta(int numeroUnita, int costoBase)
{
    int costo = 0;
    if(numeroUnita > 3)
        costo = numeroUnita * costoBase * 0.85;
    else
        costo = numeroUnita * costoBase * 0.95;

    return costo;
}

int scontoBF(int numeroUnita, int costoBase)
{
    int costo = 0;
    if(numeroUnita > 4)
    {
        costo = numeroUnita * costoBase * 0.70;
    }
    else
    {
        costo = numeroUnita * costoBase * 0.72;
    }
    return costo;
}

int calcolaCosto(int numeroUnita, int costoBase, int (*strategy)(int,int))
{
    int costo = 0;
    if(numeroUnita > 0 && costoBase > 0)
    {
        costo = strategy(numeroUnita,costoBase);
    }
    else
        costo = 0;
    
    return costo;
}