#include <stdio.h>
#include <string.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main() 
{
    int T;
    int N[101];
    char F0[101][2];
    char F1[101][2];
    char F[101][16][1000];
    char results[101][1000];

    scanf("%d", &T);

    if (T < 1 || T > 100)
    {
        return 0;
    }

    for (int i = 0; i < T; i++) 
    {
        scanf("%d %s %s", &N[i], F0[i], F1[i]);

        if (N[i] < 1 || N[i] > 15)
        {
            return 0;
        }

        strcpy(F[i][0], F0[i]);
        strcpy(F[i][1], F1[i]);

        for (int ii = 2; ii <= N[i]; ii++) 
        {
            strcpy(F[i][ii], F[i][ii - 1]);
            strcat(F[i][ii], F[i][ii - 2]);
        }

        strcpy(results[i], F[i][N[i]]);
    }

    for (int i = 0; i < T; i++)
    {
        printf("Case #%d: %s\n", i + 1, results[i]);
    }

    return 0;
}