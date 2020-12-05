#include <stdio.h>

int main() {
    int dividend, divisor;
    
    scanf("%d %d", &dividend, &divisor);
    
    if ( divisor < 0 ) {
        divisor = -divisor;
    }
    if ( (0 == dividend % divisor && dividend) || dividend <= -divisor ) {
        dividend -= dividend % divisor;
    } else {
        dividend += divisor - dividend % divisor;
    }
    printf("%d\n", dividend);
    
    return 0;
}
