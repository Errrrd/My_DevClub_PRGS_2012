#include <stdio.h>

int main() {
    int x, y, z;
    int max;
    
    scanf("%d %d %d", &x, &y, &z);
    
    max = x;
    if ( max < y ) {
    max = y;
    }
    if ( max < z ) {
    max = z;
    }
    printf("%d\n", max);
    return 0;
}
