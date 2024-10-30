#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main() 
{
    int T;
    int N[101], X[101][21];
    int F[101];

    //Input T
    scanf("%d", &T);

    if (T < 1 || T > 100)
    {
        return 0;
    }

    //Input Numbers
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &N[i], &X[i][0], &X[i][1]);

        if (N[i] < 0 || N[i] > 20)
        {
            return 0;
        }

        if (X[i][0] < -1000000000 || X[i][0] > 1000000000)
        {
            return 0;
        }

        if (X[i][1] < -1000000000 || X[i][1] > 1000000000)
        {
            return 0;
        }
    }

    //Main Calculation
    for (int i = 0; i < T; i++)
    {
        if (N[i] == 0)
        {
            F[i] = X[i][0];
        }
        else if (N[i] == 1)
        {
            F[i] = X[i][1];
        }
        else
        {
            int F0 = X[i][0];
            int F1 = X[i][1];
            int Fn;

            for (int j = 2; j <= N[i]; j++)
            {
                Fn = F1 - F0;
                F0 = F1;
                F1 = Fn;
            }

            F[i] = Fn;
        }
    }

    //Output
    for (int i = 1; i <= T; i++)
    {
        printf("Case #%d: %d\n", i, F[i-1]);
    }

    return 0;
}