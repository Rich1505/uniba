#include <stdio.h>

/**
 * @brief minimo tra 2 numeri
 */
int _min(int a, int b)
{
    return (a < b) ? a : b;
}

/**
 * @brief massimo tra 2 numeri
 */
int _max(int a, int b)
{
    return (a > b) ? a : b;
}


/**
 * @brief massimo comune divisiore tra 2 numeri
 */
int mcd(int a, int b)
{
    int min = _min(a,b);
    int max = _max(a,b);

    if (max % min == 0)
        return min;

    return mcd(min, max % min);
}

int main()
{
    int a, b;
    printf("Inserisci i 2 numeri di cui calcolare mcd: ");
    scanf("%d %d", &a, &b);

    int max = mcd(a, b);
    printf("%d", max);
}