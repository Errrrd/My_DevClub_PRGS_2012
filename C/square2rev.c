#include <stdio.h>

int main() {
    int total;
    int n;
    int k;
    
    scanf("%d", &total);
    
    for ( ; total > 1; total-- ) {
        k = total + 1;
        n = total * (k / 2) + (k % 2) * (total / 2) - total + 1;
        for ( int j = 1; j < total; j++ ) {
            printf("%d ", n);
            n += 1;
        }
        printf("%d\n", n);
    }
    printf("%d\n", total);
    
    return 0;
}
