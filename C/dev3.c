#include <stdio.h>

#define DIV 3

int main() {
    int min, max;
    
    scanf("%d %d", &min, &max);
    
    if ( min % DIV <= 0 ) {
        min -= min % DIV;
        } else {
        min += DIV - min % DIV;
        }
    for ( min; min <= max; min += DIV) {
        printf("%d\n", min);
    }
    
    return 0;
}
