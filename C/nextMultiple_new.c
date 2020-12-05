#include <stdio.h>

int main() {
    int dividend, divisor, r;
    
    scanf("%d %d", &dividend, &divisor);
    
    if ( divisor < 0 ) {
        divisor = -divisor;
    }
    r = dividend % divisor;
    if ( dividend > 0 && r != 0 ) {
        dividend += divisor;
    }
    
    printf("%d\n", dividend-r);
    
    return 0;
}
