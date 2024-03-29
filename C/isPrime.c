#include <stdio.h>

int isPrime(int n) {
    for ( int i = 2; i * i <= n; i++ ) {
        if ( n % i == 0 ) {
            return 0;
        }
    }
    if ( n > 1 ) {
        return 1;
    }
    return 0;
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    printf("%d\n", isPrime(n));
    
    return 0;
}
