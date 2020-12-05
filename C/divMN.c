#include <stdio.h>

int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int min, max, m, n;
    int div;
    
    scanf("%d %d %d %d", &min, &max, &m, &n);
    
    div = lcm(m, n);
    if ( min % div > 0 ) {
        min += div - min % div;
    } else {
        min -= min % div;
    }
    for ( ; min <= max; min += div ) {
        printf("%d\n", min);
    }
    
    return 0;
}
