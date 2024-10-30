#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    int N, M;

    scanf("%d", &N);

    if (N < 0 || N > 5000)
    {
        return 1;
    }
    
    M = (N + 2) * (N + 1) / 2;

    printf("%d\n", M);

    return 0;
}