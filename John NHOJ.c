#include <stdio.h> 
#include <string.h> 
#include <ctype.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    int T;

    scanf("%d", &T);

    if (T < 1 || T > 100)
    {
        return 0;
    }
    
    char X[T][1001]; 

    for (int i = 0; i < T; i++)
    {
        char S[1001]; 
        scanf("%s", S);

        if (S < 'a' ||  S > 'Z')
        

        for (int j = 0; S[j] != '\0'; j++) 
        {
            if (isupper(S[j]))
            {
                S[j] = tolower(S[j]);
            }
            else if (islower(S[j]))
            {
                S[j] = toupper(S[j]);
            }
        }

        strcpy(X[i], S);
    }

    for (int i = 0; i < T; i++)
    {
        printf("Case #%d: ", i + 1);

        for (int j = strlen(X[i]) - 1; j >= 0; j--)
        {
            printf("%c", X[i][j]);
        }

        printf("\n");
    }

    return 0;
}