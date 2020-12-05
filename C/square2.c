#include <stdio.h>

int main() {
    int size;
    int n;
    
    scanf("%d", &size);
    
    n = 0;
    for ( int i = 1; i <= size; i++ ) {
        n += 1;
        for ( int j = 1; j < size; j++ ) {
            printf("%d ", n);
            n += 1;
        }
        printf("%d\n", n);
    }
    
    return 0;
}
