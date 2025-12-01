#include<stdio.h>
#include<ctype.h>
#define SIZE 100

int isVowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    char str[SIZE];
    printf("Inserisci stringa: ");
    gets_s(str,SIZE-1);

    for(int i = 0;i<SIZE;i++)
    {
        if(str[i] == '\0')
            break;

        if(isVowel(str[i]))
        {
            printf("Ho letto la vocale %c in posizione %d\n",str[i],i+1);
        }
    }
}