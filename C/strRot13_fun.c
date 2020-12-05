#include <stdio.h>

#define SIZE 101

void strRot13(char str[]) {
    for ( char *symbol = str; *symbol != 0; symbol++ ) {
        if ( *symbol >= 65 && *symbol <= 90 ) {
            if ( *symbol > 77 ) {
                *symbol -= 13;
            } else {
                *symbol += 13;
            }
        }
        if ( *symbol >= 97 && *symbol <= 122 ) {
            if ( *symbol > 109 ) {
                *symbol -= 13;
            } else {
                *symbol += 13;
            }
        }
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str[SIZE];
    
    fscanf(in, "%100s", str);
    fclose(in);
    strRot13(str);
    fprintf(out, "%s\n", str);
    fclose(out);
    
    return 0;
}