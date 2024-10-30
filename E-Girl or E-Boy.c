#include <stdio.h>
#include <ctype.h>
#include <string.h>

//disuruh dikasi catatan biar ga dikira copas hehe
int main() 
{
    int T;
    char A[101][10000];
    int x[101];

    scanf("%d", &T);

    if (T < 1 || T > 100)
    {
        return 0;
    }
    
    getchar();

    for (int i = 0; i < T; i++) 
    {
        fgets(A[i], sizeof(A[i]), stdin);

        if (strlen(A[i]) < 1 || strlen(A[i]) > 100000)
        {
            return 0;
        }
        

        A[i][strcspn(A[i], "\n")] = '\0';

        int alphabetCount[26] = {0};
        int uniqueCount = 0;

        for (int j = 0; A[i][j] != '\0'; j++) 
        {
            if (isalpha(A[i][j])) 
            {
                char lowercaseChar = tolower(A[i][j]);
                int index = lowercaseChar - 'a';

                if (alphabetCount[index] == 0) 
                {
                    uniqueCount++;
                    alphabetCount[index] = 1;
                }
            }
        }

        x[i] = (uniqueCount % 2 == 0) ? 1 : 0;
    }

    for (int i = 0; i < T; i++) 
    {
        printf("Case #%d: ", i + 1);
        
        if (x[i] == 1) 
        {
            printf("Yay\n");
        } 
        else 
        {
            printf("Ewwww\n");
        }
    }

    return 0;
}