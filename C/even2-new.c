#include <stdio.h>

int main() {
    int first, second;
    
    scanf("%d %d", &first, &second);
    
    if ( first % 2 != 0 ) {
        first += 1;
    }
    for ( ; first < second - 1; first += 2 ) {
        printf("%d ", first);
    }
    printf("%d\n", first);
    
    return 0;
}
