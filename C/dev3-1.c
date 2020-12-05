#include <stdio.h>

#define DIV 3

int main() {
    int min, max;
    int r;
    
    scanf("%d %d", &min, &max);
    
    r = min % DIV;
    if ( r < 0 ) {
        r = -r;
    }
    for ( min += r ; min <= max; min += DIV ) {
        printf("%d\n", min);
    }
    
    return 0;
}
