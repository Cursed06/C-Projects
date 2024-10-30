#include <stdio.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main() 
{
    int T, N = 1;

    scanf("%d", &T);

    if (T < 1 || T > 100)
    {
        return 1;
    }

    char hasil[T][15]; 

    while (N <= T) 
    {
        int Z;
        char C[101] = "";

        scanf("%s", C);

        int counter = 0;

        for (Z = 0; Z < 101; Z++) 
        { 
            if (C[Z] == '.') 
            {
                if (C[Z - 1] != '.' && C[Z + 1] != '.') 
                {
                    counter++;
                }
            }
        }

        if (counter == 5) 
        {
            sprintf(hasil[N - 1], "Case #%d: YES", N);
        } else {
            sprintf(hasil[N - 1], "Case #%d: NO", N);
        }
        N++;
    }

    for (int i = 0; i < T; i++) 
    {
        printf("%s\n", hasil[i]);
    }

    return 0;
}
