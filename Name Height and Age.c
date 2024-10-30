#include <stdio.h>
#include <string.h>

int main()
{
    char Nama1[101], Nama2[101];
    double T1, T2;
    int U1, U2;

    scanf("%100s %lf %d %100s %lf %d", Nama1, &T1, &U1, Nama2, &T2, &U2);

    // Check Constraints for Name
    if (strlen(Nama1) < 1 || strlen(Nama1) > 100) {
        printf("\n");
        return 1; 
    }

  if (strlen(Nama2) < 1 || strlen(Nama2) > 100) {
        printf("\n");
        return 1; 
    }

    // Check Constraints for Height
    if (T1 < 1 || T1 > 300) {
        printf("\n");
        return 1; 
    }

    if (T2 < 1 || T2 > 300) {
        printf("\n");
        return 1; 
    }

    // Check Constraints for Age
    if (U1 < 1 || U1 > 100) {
        printf("\n");
        return 1; 
    }

    if (U2 < 1 || U2 > 100) {
        printf("\n");
        return 1; 
    }

    printf("Name 1: %s\n", Nama1);
    printf("Height 1: %.2lf\n", T1);
    printf("Age 1: %d\n", U1);
    
    printf("Name 2: %s\n", Nama2);
    printf("Height 2: %.2lf\n", T2);
    printf("Age 2: %d\n", U2);

    return 0;
}
