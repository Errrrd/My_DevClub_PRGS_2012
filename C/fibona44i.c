#include <stdio.h>

int main() {
    int n;
    int fib;
    
    scanf("%d", &n);
    
    fib = 1;
    for ( int i = 3; i <= n; i++ ) {
        temp = fib;
        fib += temp ;
    }
    printf("%d\n", fib);
    
    return 0;
}
