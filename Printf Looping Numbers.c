#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    int N, M, O;

    scanf("%d %d", &N, &M);

    if (N < 1 || N > 100)
    {
        return 1;
    }
    
    if (M < 1 || M > 10)
    {
        return 1;
    }
    

    for (O = 0; O <= M; O++)
    {
        printf("%d\n", N);
        N++;
    }

    return 0;   
}