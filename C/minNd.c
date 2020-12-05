#include <stdio.h>

int main() {
    int quantity, number, min;
    
    scanf("%d %d", &quantity, &number);
    min = number;
    for ( ; quantity > 1; quantity-- ) {
        scanf("%d", &number);
        if ( min > number ) {
            min = number;
        }
    }
    printf("%d\n", min);
    
    return 0;
}
