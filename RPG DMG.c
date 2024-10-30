#include <stdio.h>
#include <math.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    double P, M, T;
    double x, y, z;
    double DMG;

    scanf("%lf %lf %lf", &P, &M, &T);

    if (P < 0 || P > 100)
    {
        return 1;
    }

    if (M < 0 || M > 100)
    {
        return 1;
    }
    
    if (T < 0 || T > 100)
    {
        return 1;
    }

    x = P * 0.2;
    y = M * 0.3;
    z = T * 0.5;

    DMG = x + y + z;

    printf("%.2lf\n", DMG);
    return 0;
}