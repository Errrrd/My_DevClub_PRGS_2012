#include <stdio.h>

#define MAX 1000000

int isPrime(int prime) {
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
