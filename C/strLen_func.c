#include <stdio.h>

#define SIZE 100

int strLen(char str[]) {
    int len = 0;
    
    for ( ; str[len] != 0; len++ );
    return len;
}

int main() {
    char str[SIZE];
    
    scanf("%s", &str);
    
    printf("%d\n", strLen(str));
    
    return 0;
}
