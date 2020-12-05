#include <stdio.h>

int gcd(int a, int b) {
    if ( a < 0 ) {
        a *= -1;
    }
    if ( b < 0 ) {
        b *= -1;
    }
    gcd = b;
    for ( ;a % gcd != 0 || b % gcd != 0; ) {
        if ( a > b ) {
            a -= b;
            gcd = a;
        }
        if ( a < b ) {
            b -= a;
            gcd = b;
        }
    }
    return gcd;
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    printf("%d %d\n", a, b);

    return 0;
}
