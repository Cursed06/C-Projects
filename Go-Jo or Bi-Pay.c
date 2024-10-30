#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    int T, A, B;
    int X;

    scanf("%d", &T);

    char hasil[T][10];

    if (T < 1 || T > 1000)
    {
        return 1;
    }
    

    for (int i = 0; i < T; i++) 
    {
        int A, B;
        scanf("%d %d", &A, &B);

        if (A < 0 || A > 100)
        {
            break;
        }

        if (B < 0 || B > 100)
        {
            break;
        }
        
        if (A == B)
        {
            break;
        }
        
        
        if (A > B) 
        {
            snprintf(hasil[i], sizeof(hasil[i]), "Go-Jo");
        } else {
            snprintf(hasil[i], sizeof(hasil[i]), "Bi-Pay");
        }
    }


    for (int i = 0; i < T; i++) 
    {
        printf("Case #%d: %s\n", i + 1, hasil[i]);
    }
    
    return 0;
}