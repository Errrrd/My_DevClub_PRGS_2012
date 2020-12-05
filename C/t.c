#include <stdio.h>

int main() {
    int min, max, divisor;
    int r;
    
    scanf("%d %d %d", &min, &max, &divisor);
    r = min % divisor;
    min -= r;
    if ( r > 0 ) {
        min += divisor;
    }
    for ( ; min <= max; min += divisor ) {
        printf("%d\n", min);
    }
    
    return 0;
}
