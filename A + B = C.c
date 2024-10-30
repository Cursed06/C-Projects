#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    int a, b, c;

    scanf("%d %d", &a, &b);

    if (a < 0 || a > 1000)
    {
        return 1;
    }

    if (b < 0 || a > 1000)
    {
        return 1;
    }
    
    c = a + b;
    printf ("%d\n", c);

    return 0;
}