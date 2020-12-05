#include <stdio.h>

int main() {
    int x, y, z;
    
    scanf("%d %d %d", &x, &y, &z);
    
    if ( x + y > z ) {
        printf("alpha\n");
    } else if ( x < y - z ) {
        printf("bravo\n");
    } else if ( y % z == 0 ) {
        printf("charlie\n");
    } else {
        printf("zulu\n");
    }
    
    return 0;
}
