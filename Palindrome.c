#include <stdio.h>
#include <string.h>
#include <ctype.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main() 
{
    int T;

    scanf("%d", &T);

    if (T < 1 || T > 1000)
    {
        return 0;
    }

    char S[T][501];
    char X[T][30];

    for (int i = 0; i < T; i++)
    {
        scanf("%s", S[i]);

        if (strlen(S[i]) < 1 || strlen(S[i]) > 500)
        {
            return 0;
        }

        int L = 0;
        int R = strlen(S[i]) - 1;
        int P = 1;

        while (L < R) 
        {
            if (tolower(S[i][L]) != tolower(S[i][R])) 
            {
                P = 0;
                break;
            }
            L++;
            R--;
        }

        if (P) 
        {
            strcpy(X[i], "Yay, it's a palindrome");
        } 
        else
        {
            strcpy(X[i], "Nah, it's not a palindrome");
        }
    }

    for (int i = 0; i < T; i++)
    {
        printf("Case #%d: %s\n", i + 1, X[i]);
    }

    return 0;
}