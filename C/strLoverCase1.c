#include <stdio.h>

#define SIZE 101

void strLowerCase(char str[]) {
    for ( int *i = str; *i != 0; i++ ) {
        if ( *i >= 65 && *i <= 90) {
            *i += 32;
        }
        printf("%c ", *i);
    }
    printf("\n");
}

int main() {
    FILE *in = fopen("task.in", "r");
    //FILE *out = fopen("task.out", "w");
    char str[SIZE];
    
    fscanf(in, "%s", str);
    printf("%s\n", str);
    fclose(in);
    strLowerCase(str);
    
    return 0;
}
