#include <stdio.h>

#define DEV 5

int main() {
    int min, max;
    int r;
    
    scanf("%d %d", &min, &max);
    r = min % DEV;
    min -= r;
    if ( r > 0 ) {
        min += DEV;
    }
    for ( ; min <= max; min += DEV ) {
        printf("%d\n", min);
    }
    
    return 0;
}
