#include <stdio.h>

#define MAX 1000000

int isPrime(int prime) {
    if ( prime < 2 ) {
        return -1;
    }
    if ( prime % 2 == 0 ) {
        return 0;
    }
    for ( int i = 3; i * i <= prime; i += 2 ) {
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
    
    /*if ( n <= 0 || n > MAX ){
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
    printf("%d", prime);
    */
    
    if ( n <= 0 || n > 2147483629 ) {
        printf("-1\n");
    }
    printf ("2 1\n");
    for ( int i = 2; i <= n; ) {
            prime += 2;
        if ( isPrime( prime ) == 1 ) {
            printf("%d %d\n", prime, i);
            i += 1;
        }
    }
    
    return 0;
}
