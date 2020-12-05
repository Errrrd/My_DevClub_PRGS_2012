#include <stdio.h>

int main() {
    int dividend, divisor;
    int max;
    
    scanf("%d %d", &dividend, &divisor);
    
    if ( divisor < 0 ) {
        divisor = -divisor;
    }
    if ( dividend%divisor > 0 || dividend == 0 ) {
        max = dividend - dividend % divisor + divisor;
    } else {
        max = dividend - dividend % divisor;
    }
    printf("%d\n", max);
    
    return 0;
}
