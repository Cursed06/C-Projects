#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main() 
{
    int F[31];
    int K;

    scanf("%d %d", &F[0], &F[1]);

    if (F[0] < -1000 || F[0] > 1000)
    {
        return 0;
    }

    if (F[1] < -1000 || F[1] > 1000)
    {
        return 0;
    }
    
    scanf("%d", &K);

    if (K < 1 || K > 30)
    {
        return 0;
    }
    
    for (int i = 2; i <= K + 1; i++) 
    {
        F[i] = F[i-1] + F[i-2];
    }

    printf("%d\n", F[K]);

    return 0;
}