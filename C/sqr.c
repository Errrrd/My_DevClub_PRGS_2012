#include <stdio.h>

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

int main() {
    int n;
    
    scanf("%d", &n);
    
    n = sqrN(n);
    printf("%d\n", n);
    
    return 0;
}
