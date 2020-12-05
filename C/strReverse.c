#include <stdio.h>

#define SIZE 101

int strLen(char str[]) {
    int len = 0;
    
    for ( ; str[len] != 0; len++ );
    return len;
}

void strReverse(char str[], int len) {
    char tmp;
    
    for ( int i = 0, last = len - 1; i < last; i++, last-- ) {
        tmp = str[i];
        str[i] = str[last];
        str[last] = tmp;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char str[SIZE];
    
    fscanf(in, "%s", str);
    fclose(in);
    strReverse(str, strLen(str));
    fprintf(out, "%s\n", str);
    fclose(out);
    
    return 0;
}
