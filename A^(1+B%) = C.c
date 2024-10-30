#include <stdio.h>
#include <math.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    double x, y, z;

    scanf("%lf %lf", &x, &y);

    if (x < 1 || x > 100000)
    {
        return 1;
    }
    
    if (y < 0.00 || y > 1000.00)
    {
        return 1;
    }
    
    z = x * pow(1 + (y / 100), 3);

    printf("%.2lf\n", z);
    return 0;
}