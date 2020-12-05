#include <stdio.h>

int main() {
    int size;
    
    scanf("%d", &size);
    
    for ( int i = 1; i <= size; i++ ) {
        for ( int j = 1; j < size; j++ ) {
            printf("%d ", j);
        }
        printf("%d\n", size);
    }
    
    return 0;
}
