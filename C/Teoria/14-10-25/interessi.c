#include <stdio.h>
#include <math.h>
int main()
{
    int contA = 0, contB = 0, contC = 0, contD = 0;
    int grade = 0;
    //getchar blocca l'esecuzione quando il buffer dei caratteri inseriti da tastiera è vuoto
    //estrae un solo byte dal buffer, quindi se inserisco caratteri non appartenenti all'ascii non lo prenderà
    while ((grade = getchar()) != EOF)
    {
        while(getchar() != '\n');
        switch (grade)
        {
        case 'A':
        // accomunare
        case 'a':
        {
            contA++;
            break;
                    }
        case 'B':
        case 'b':
        {
            ++contB;
            break;
        }
        case 'C':
        case 'c':
        {
            ++contC;
            break;
        }
        case 'D':
        case 'd':
        {
            ++contD;
            break;
        }
        default:
            break;
        }
    }

    printf("numero di a:%d ", contA);
    printf("numero di b:%d ", contB);
    printf("numero di c:%d ", contC);
    printf("numero di d:%d ", contD);

    return 0;
}