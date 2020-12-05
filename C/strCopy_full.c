#include <stdio.h>

#define SIZE 101

void strCopy(char target[], char source[]) {
    int i = 0;
    
    for ( ; source[i] != 0; i++ ) {
        target[i] = source[i];
    }
    target[i] = 0;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str1[SIZE];
    char str2[SIZE];
    
    fscanf(in, "%s %s", str1, str2);
    fclose(in);
    if ( strEqual(str1, str2) ) {
        fprintf(out, "yes\n");
    } else {
        fprintf(out, "no\n");
    }
    fclose(out);
    
    return 0;
}
