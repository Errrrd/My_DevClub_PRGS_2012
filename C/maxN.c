#include <stdio.h>

int main() {
    int n, num;
    int max;
    
    scanf("%d %d", &n, &num);
    max = num;
    for ( ; n > 1; n-- ) {
        scanf("%d", &num);
        if ( max < num ) {
            max = num;
        }
    }
    printf("%d\n", max);
    
    return 0;
}
