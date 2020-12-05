#include <stdio.h>

int main() {
    int n;
    int num;
    int max;
    
    scanf("%d\n", &n);
    max = -2147483648;
    for ( int i = 1; i <= n; i++ ) {
        scanf(" %d", &num);
        if ( max < num ) {
            max = num;
        }
    }
    printf("%d\n", max);
    
    return 0;
}
