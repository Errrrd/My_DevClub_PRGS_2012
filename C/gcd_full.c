#include <stdio.h>

int gcd(int a, int b) {
    if ( a == b ) {
        return a;
    }
    if ( a == 1 || b == 1 ) {
        return 1;
    }
    if ( a % 2 == 0 && b % 2 == 0 ) {
        return 2 * gcd(a/2, b/2);
    }
    if ( a % 2 == 0 && b % 2 == 1 ) {
        return gcd(a/2, b);
    }
    if ( a % 2 == 1 && b % 2 == 0 ) {
        return gcd(a, b/2);
    }
    if ( a % 2 == 1 && b % 2 == 1 ) {
        int dif = a - b;
        
        if ( a > b ) {
            return gcd(dif/2, b);
        } else {
            dif = b - a;
            return gcd(dif/2, a);
        }
    }
    return a;
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    printf("%d %d\n", a, b);

    return 0;
}
