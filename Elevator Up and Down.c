#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    int X, Y, K;
    int a, b;
    scanf("%d %d %d", &X, &Y, &K);

    a = K - X;
    b = Y - K;

    if (X < 0 || X > 100)
    {
        return 1;
    }
    
    if (Y < 0 || Y > 100)
    {
        return 1;
    }

    if (K < 0 || K > 100)
    {
        return 1;
    }

    if (a == b && a >= 0)
    {
        printf("%d\n", a);
    }
    else
    {
        printf("-1\n");
    }
    
    return 0;
}