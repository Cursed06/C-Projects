#include <stdio.h>
#include <string.h>

int main()
{
    char S[101];

    scanf("%100s", S);

    if (strlen(S) < 1 || strlen(S) > 100) {
        printf("\n");
        return 1; 
    }

    printf("%s-san\n", S);

    return 0;
}
