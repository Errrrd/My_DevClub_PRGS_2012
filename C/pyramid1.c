#include <stdio.h>

int main() {
    int total, i, j;
    
    scanf("%d", &total);
    
    for ( i = 1; i <= total; i++ ) {
        for ( j = 1; j < i; j++ ) {
            printf("%d ", j);
        }
        printf("%d\n", j);
    }
    
    return 0;
}
