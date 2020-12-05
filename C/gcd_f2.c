#include <stdio.h>

int gcd(int a, int b) {
    if ( a == 0 || b == 0 ) {
        return a + b;
    }
    return gcd(b, a%b);
}
    
    int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    printf("%d %d\n", a, b);

    return 0;
}
