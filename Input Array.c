#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    int N, M, Q;
    int X, Y, A;

    scanf("%d %d %d", &N, &M, &Q);

    if (N < 1 || N > 100)
    {
        return 0;
    }
    
    if (M < 1 || M > 100)
    {
        return 0;
    }

    if (Q < 1 || Q > 100)
    {
        return 0;
    }

    int a[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            a[i][j] = 0;
        }
        
    }

    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d %d",  &X, &Y, &A);

        if (X < 0 || X >= N)
        {
            return 0;
        }
        
        if (Y < 0 || Y >= M)
        {
            return 0;
        }

        if (A < 0 || A > 100)
        {
            return 0;
        }

        a[X][Y] = A;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            printf("%d", a[i - 1][j - 1]);

            if (j != M)
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }
    
    return 0;   
}