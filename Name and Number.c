#include <stdio.h>
#include <string.h>

int main()
{
    char S[101];
    int A;

    scanf("%100s %d", S, &A);

    if (strlen(S) < 1 || strlen(S) > 100) {
        printf("\n");
        return 1; 
    }

    if (A < 1 || A > 100) {
        printf("\n");
        return 1; 
    }

    printf("%s\n", S);

    printf("%d\n", A);

    return 0;
}
