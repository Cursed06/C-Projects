#include <stdio.h>
#include <string.h>

int main()
{
    int O;
    char M[101], K[2], N[11];

    // NIM (Id)
    scanf("%10s", N);

    // Name 
    getchar();
    fgets(M, 101, stdin);
    M[strcspn(M, "\n")] = 0;

    // Class (K) and Number (O)
    scanf("%1s %d", K, &O);

    // Check N (Id)
    if (strlen(N) != 10)
    {
        return 1;
    }
    
    // Check M (Name)
    if (strlen(M) < 1 || strlen(M) > 100)
    {
        return 1;
    }
    
    // Check K (Class)
    if (K[2] < 'A' || K[2] > 'Z')
    {
        return 1;
    }
    
    // Check O (Number)
    if (O < 1 || O > 1000)
    {
        return 1;
    }
    
    // Output
    printf("Id    : %s\n", N);
    printf("Name  : %s\n", M);
    printf("Class : %s\n", K);
    printf("Num   : %d\n", O);

    return 0;
}
