#include <stdio.h>

int main() {
    int dividend, divisor;
    int r;
    
    scanf("%d %d", &dividend, &divisor);
    
    if ( divisor < 0 ) {
        divisor = -divisor;
    }
    r = dividend % divisor;
    dividend -= r;
    if ( dividend < divisor ) {
        if ( r != 0 || dividend == 0 ) {
            dividend -= divisor;
        }
    }
    printf("%d\n", dividend);
    
    return 0;
}
