#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main() 
{
    int T, X;

    scanf("%d", &T);

    if (T < 1 || T > 100)
    {
        return 0;
    }

    int b[T][100];

    for (int j = 0; j < T; j++) 
    {
        for (int k = 0; k < 100; k++) 
        {
            b[j][k] = 0;            
        }
    }

    for (int i = 0; i < T; i++) 
    {
        scanf("%d", &X);

        if (X < 1 || X > 100)
        {
            return 0;
        }

        int a[X][X];

        for (int j = 0; j < X; j++) 
        {
            for (int k = 0; k < X; k++) 
            {
                scanf("%d", &a[j][k]);

                if (a[j][k] < 0 || a[j][k] > 10000000)
                {
                    return 0;
                }
            }
        }

        for (int j = 0; j < X; j++) 
        {
            for (int k = 0; k < X; k++) 
            {
                b[i][j] += a[k][j];
            }
        }
    }

    for (int i = 0; i < T; i++) 
    {
        printf("Case #%d:", i + 1);
        for (int j = 0; j < 100; j++) 
        {
            if (b[i][j] != 0)
            {
                printf(" %d", b[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}