#include <stdio.h>

int main() {
    int max, divisor;
    int i;
    
    scanf("%d %d", &max, &divisor);
    if ( divisor < 0 ) {
    divisor = -divisor;
    }
    max -= divisor - 1;
    for ( i = 0; i < max; i += divisor ) {
        printf("%d ", i);
    }
    printf("%d\n", i);
    
    return 0;
}
