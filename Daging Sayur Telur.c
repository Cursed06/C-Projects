#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    int D, S, T;

    scanf("%d %d %d", &D, &S, &T);

    //Constraints
    if (D < 0 || D > 1000000)
    {
        return 1;
    }
    
    if (S < 0 || S > 1000000)
    {
        return 1;
    }

    if (T < 0 || T > 1000000)
    {
        return 1;
    }

    if (D == S || S ==  T || D == T)

    {
        return 1;
    }

    //Main Comparison
    if (D > S && S > T)
    {
        printf("Daging\nSayur\nTelur\n");
    }
    else if (D > T && T > S)
    {
        printf("Daging\nTelur\nSayur\n");
    }
    else if (S > D  && D > T)
    {
        printf("Sayur\nDaging\nTelur\n");
    }
    else if (S > T && T > D)
    {
        printf("Sayur\nTelur\nDaging\n");
    }
    else if (T > D  && D > S)
    {
        printf("Telur\nDaging\nSayur\n");
    }
    else if (T > S && S > D)
    {
        printf("Telur\nSayur\nDaging\n");
    }
    
    return 0;   
}