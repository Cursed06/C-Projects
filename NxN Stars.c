#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    int N, M, O;

    scanf("%d", &N);

    if (N < 1 || N > 100)
    {
        return 1;
    }
    
    for (M = 1; M <= N; M++)
    {
        for (O = 1; O <= N; O++)
        {
            printf("*");
        }
        
        printf("\n");
    }
    
    return 0;
}