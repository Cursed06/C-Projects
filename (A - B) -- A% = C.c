#include <stdio.h>
#include <math.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    float a, b, c;

    scanf("%f %f", &a, &b);

    if (b < 1 || b > a || a < b || a > 100000)
    {
        return 1;
    }
    
    c = (a - b)/ a * 100;

    printf("%.2f%%\n", c);
    return 0;
}