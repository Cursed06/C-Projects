#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    int T; int N; int M[101];
    int A[101][2][101], B[101][2][101];

    scanf("%d", &T);

    if (T < 1 || T > 100)
    {
        return 0;
    }

    for (int x = 0; x < T; x++)
    {
        scanf("%d", &N);

        if (N < 1 || N > 100)
        {
            return 0;
        }
        
        M[x] = N;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &A[x][i][j]);

                if (A[x][i][j] < 1 || A[x][i][j] > 100000)
                {
                    return 0;
                }
                
            }

        }

        for (int i = 0; i < N; i++)
        {
            B[x][0][i] = A[x][0][i] - A[x][1][i];

        }
    }
    
    for (int i = 0; i < T; i++)
    {
        printf("Case #%d:", i + 1);

        for (int j = 0; j < M[i]; j++)
        {
            printf(" %d", B[i][0][j]);
        }

        printf("\n");
    }


    return 0;   
}