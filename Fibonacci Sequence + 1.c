#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    int T, N;
    int x[30];

    scanf("%d", &T);

    if (T < 1 || T > 30)
    {
        return 0;
    }
    

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);

        if (N < 1 || N > 30)
        {
            return 0;
        }
        
        int C[N + 1];

        C[0] = 1;
        if (N >= 1) C[1] = 1;

        for (int j = 2; j <= N; j++)
        {
            C[j] = C[j - 1] + C[j - 2] + 1;
        }

        x[i] = C[N];
    }

    for (int i = 0; i < T; i++)
    {
        printf("Case #%d: %d\n", i + 1, x[i]);
    }
    
    return 0;   
}