#include <stdio.h>
#include <string.h>
#include <ctype.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main()
{
    char S[10001];

    fgets(S, sizeof(S), stdin);

    for (int i = 0; i < strlen(S); i++)
    {
        if (toupper(S[i]) == 'I')
        {
            printf("1");
        }
        else if (toupper(S[i]) == 'R')
        {
            printf("2");
        }
        else if (toupper(S[i]) == 'E')
        {
            printf("3");
        }
        else if (toupper(S[i]) == 'A')
        {
            printf("4");
        }
        else if (toupper(S[i]) == 'S')
        {
            printf("5");
        }
        else if (toupper(S[i]) == 'G')
        {
            printf("6");
        }
        else if (toupper(S[i]) == 'T')
        {
            printf("7");
        }
        else if (toupper(S[i]) == 'B')
        {
            printf("8");
        }
        else if (toupper(S[i]) =='P')
        {
            printf("9");
        }
        else if (toupper(S[i]) == 'O')
        {
            printf("0");
        }
        else
        {
            printf("%c", toupper(S[i]));
        }
    }
    
    return 0;   
}