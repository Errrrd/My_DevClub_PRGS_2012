#include <stdio.h>

int main() {
    int total, j;
    
    scanf("%d", &total);
    
    for (; total > 0; total-- ) {
        for ( j = 1; j < total; j++ ) {
            printf("%d ", j);
        }
        printf("%d\n", j);
    }
    
    return 0;
}
