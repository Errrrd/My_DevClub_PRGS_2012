#include <stdio.h>

#define SIZE 101

int strLen(char str[]) {
    int len = 0;
    
    for ( ; str[len] != 0; len++ );
    return len;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str[SIZE];
    
    fscanf(in, "%s", str);
    fclose(in);
    fprintf(out, "%d\n", strLen(str));
    fclose(out);
    return 0;
}
