#include <stdio.h>

int main() {
    int base, exp;
    int num;
    
    scanf("%d %d", &base, &exp);
    
    num = 1;
    for ( int i = 0; i < exp; i++ ) {
        printf("%d ", num);
        num *= base;
    }
    printf("%d\n", num);
    
    return 0;
}
