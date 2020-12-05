#include <stdio.h>

#define SIZE 100

void strRot13(char str[]) {
    int symbol = str[0];
    for ( int i = 0; symbol != 0; ) {
        if ( symbol >= 65 && symbol <= 90 ) {
            if ( symbol > 77 ) {
                str[i] -= 13;
            } else {
                str[i] += 13;
            }
        }
        if ( symbol >= 97 && symbol <= 122 ) {
            if ( symbol > 109 ) {
                str[i] -= 13;
            } else {
                str[i] += 13;
            }
        }
        i += 1;
        symbol = str[i];
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str[SIZE];
    
    fscanf(in, "%s", str);
    fclose(in);
    strRot13(str);
    fprintf(out, "%s\n", str);
    fclose(out);
    
    return 0;
}
