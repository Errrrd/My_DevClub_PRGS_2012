#include <stdio.h>

#define SIZE 101

int strLen(char str[]) {
    int len = 0;
    
    for ( ; str[len] != 0; len++ );
    return len;
}

int strEqual(char str1[], char str2[]) {
    for ( int i = 0; str1[i] != 0 || str2[i] != 0; i++ ) {
        if ( str1[i] != str2[i] ) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str1[SIZE];
    char str2[SIZE];
    
    fscanf(in, "%s %s", str1, str2);
    fclose(in);
    fprintf(out, "%d\n", strEqual(str1, str2));
    fclose(out);
    
    return 0;
}