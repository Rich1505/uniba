#include"myMath.h"

long long int factorial(long long int n)
{
    return (n > 0) ? n*factorial(n-1) : 1;
}

long long int fibonacci(long long int n)
{
    if(n == 0)
    return 0;

    if(n == 1)
    return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}