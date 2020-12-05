#include <stdio.h>

int main() {
    int dividend, divisor;
    int max;
    
    scanf("%d %d", &dividend, &divisor);
    
    if ( divisor < 0 ) {
        divisor = -divisor;
    }
    max = dividend - dividend % divisor;
    if ( dividend > -divisor && dividend % divisor != 0 ) {
        max += divisor;
    }
    if ( max == 0 ) {
        max += divisor;
    }
    printf("%d\n", max);
    
    return 0;
}
