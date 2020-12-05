#include <stdio.h>

int main() {
    int n;
    int fib, temp1, temp2;
    
    scanf("%d", &n);
    
    fib = 1;
    temp1 = 1;
    for ( ; n > 2; n-- ) {
        temp2 = temp1;
        temp1 = fib;
        fib = temp1 + temp2 ;
    }
    printf("%d\n", fib);
    
    return 0;
}
