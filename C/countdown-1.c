#include <stdio.h>

int main() {
    int lim;
    int i;
    
    scanf("%d", &lim);
    
    for ( i = lim; i > 0; i-- ) {
        printf("%d ", i);
    }
    printf("%d", i);
    return 0;
}
