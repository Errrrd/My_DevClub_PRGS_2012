#include <stdio.h>

int main() {
    int n;
    int fib, temp1, temp2, k;
    
    scanf("%d", &n);
    fib = 0;
    temp1 = 1;
    k = -1;
    if ( n > 0 ) {
        for ( ; 0 < n; n-- ) {
            temp2 = temp1;
            temp1 = fib;
            fib = temp1 + temp2 ;
        }        
    } else {
        for ( ; 0 > n; n++ ) {
            temp2 = temp1;
            temp1 = fib;
            fib = (temp1 + temp2) ;
        k *= -1;
        }
        fib *= k;
    }
    printf("%d\n", fib);
    return 0;
}
