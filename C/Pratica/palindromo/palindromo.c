#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100

int _isPalindromeRicursive(char str[],int n)
{
    size_t size = strlen(str);

    if(str[n] != str[size-n-1])
    {
        return 0;
    }

    if(n >= size/2)
    {
        return 1;
    }

    return _isPalindromeRicursive(str,n+1);
}

int isPalindromeRicursive(char str[])
{
    size_t size = strlen(str);

    char *str_aux = malloc(size * sizeof(char));

    int count = 0;
    for(int i = 0;i<size;i++)
    {
        if(str[i] != ' ' && isalpha(str[i]))
        {
            str_aux[count] = tolower(str[i]);
            count++;
        }
    }
    str_aux[count+1] = '\0';

    int palindrome = _isPalindromeRicursive(str_aux,0);
    free(str_aux);
    return palindrome;

}

int isPalindromeIterative(char str[])
{

    size_t size = strlen(str);

    char *str_aux = malloc(size * sizeof(char));

    int count = 0;
    for(int i = 0;i<size;i++)
    {
        if(str[i] != ' ' && isalpha(str[i]))
        {
            str_aux[count] = tolower(str[i]);
            count++;
        }
    }
    str_aux[count+1] = '\0';

    size = strlen(str_aux);
    for(size_t i = 0;i<size/2;i++)
    {
        if(str_aux[i] != str_aux[size-i-1])
        {
            free(str_aux);
            return 0;
        }
    }
    free(str_aux);
    return 1;
}

int main()
{
    char str[MAX];

    printf("Inserisci stringa: ");
    gets_s(str,MAX);
    
    int palindromo = isPalindromeRicursive(str);

    if(palindromo)
    {
        printf("\nPalindromo");
    }
    else
    {
        printf("\nNon palindromo");
    }

}