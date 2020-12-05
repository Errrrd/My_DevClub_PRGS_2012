#include <stdio.h>

int main() {
    int n, factorial;
    
    scanf("%d", &n);
    factorial = 1;
    if ( n < 0 ) {
        factorial = -1;
    }
    for ( int i = 2; i <= n; i++ ) {
        factorial *= i;
    }
    printf("%d\n", factorial);
    
    return 0;
}
