#include <stdio.h>

#define DEV 3

int main() {
    int min, max;
    
    scanf("%d %d", &min, &max);
    
    min = min - min % DEV;
    if ( min % DEV > 0 ) {
        min += DEV;
    }
    for ( ; min <= max; min += DEV ) {
        printf("%d\n", min);
    }
    
    return 0;
}
