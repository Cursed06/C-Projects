#include <stdio.h>
#include <string.h>

int main() 
{
    char S[101];

    fgets(S, 101, stdin);

    size_t len = strlen(S);
    if (len > 0 && S[len - 1] == '\n') {
        S[len - 1] = '\0';
    }

    printf("#include <stdio.h>\n");
    printf("int main()\n");
    printf("{\n");
    printf("    printf(\"%%s\\n\", \"%s\");\n", S);
    printf("    return 0;\n");
    printf("}\n");
    
    return 0;
}
