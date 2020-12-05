#include <stdio.h>

int isPrime(int n) {
    for ( int i = 2; i * i <= n; i ++ ) {
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
    //int n = 2147483647;
    int i = 1;
    
    //scanf("%d", &n);
    
    for ( int n = 3; n < 32767; n += 2 ) {
        if ( isPrime(n) == 1 ) {
            i += 1;
            printf("%d - %d\n", n, i);
        }
    }
    return 0;
}
