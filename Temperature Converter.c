#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    int T;
    double a, b, c;

    double e, f, g;
    double j, k, l;
    double x, y, z;

    scanf("%d", &T);

    if (T != 3)
    {
        return 1;
    }
    
    //Input
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    //Constraints
    if (a < 1 || a > 100)
    {
        return 1;
    }
    
    if (b < 1 || b > 100)
    {
        return 1;
    }

    if (c < 1 || c > 100)
    {
        return 1;
    }


    //First input
    e = a * (4.0 / 5.0);
    f = a * (9.0 / 5.0) + 32;
    g = a + 273;

    //Second input
    j = b * (4.0 / 5.0);
    k = b * (9.0 / 5.0) + 32;
    l = b + 273;

    //Third input
    x = c * (4.0 / 5.0);
    y = c * (9.0 / 5.0) + 32;
    z = c + 273;

    //Output
    printf("%.2lf %.2lf %.2lf\n", e, f, g);
    printf("%.2lf %.2lf %.2lf\n", j, k, l);
    printf("%.2lf %.2lf %.2lf\n", x, y, z);

    return 0;
}