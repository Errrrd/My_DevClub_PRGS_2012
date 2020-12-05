#include <stdio.h>

#define MAX 1000000

int sqrN(int n) {
    int x = 0;
    if ( n < 0 ) {
        return -1;
    }
    if ( n == 0 ) {
        return 0;
    }
    for ( int i = 1; n >= i; i += 2 ) {
        n -= i;
        x += 1;
    }
    
    return x;
}


int isPrime(int prime) {
    int sqr = sqrN(prime);
    for ( int i = 3; i <= sqr; i += 2 ) {
        if ( prime % i == 0 ) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    int prime = 1;
    
    scanf("%d", &n);
    
    if ( n <= 0 || n > MAX ) {
        prime = -1;
    } else if ( n == 1 ) {
        prime = 2;
    } else {
        for ( int i = 1; i < n; ) {
            prime += 2;
            if ( isPrime(prime) ) {
                i += 1;
            }
        }
    }
    printf("%d\n", prime);
    
    return 0;
}
