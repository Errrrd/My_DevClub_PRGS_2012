#include <stdio.h>

int main() {
    int total;
    int n;
    
    scanf("%d", &total);
    
    n = 0;
    for ( int i = 1; i <= total; i++ ) {
        n += 1;
        for ( int j = 1; j < i; j++ ) {
            printf("%d ", n);
            n += 1;
        }
        printf("%d\n", n);
    }
    
    return 0;
}
