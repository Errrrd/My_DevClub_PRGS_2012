#include <stdio.h>

int main() {
    int total, rows, cols;
    int i, j;
    
    scanf("%d %d %d", &total, &rows, &cols);
    
    if ( rows < cols ) {
        rows = cols;
    }
    for ( i = rows + 1; i <= total; i++ ) {
        for ( j = cols + 1; j < i; j++ ) {
            printf("%d ", j);
        }
        printf("%d\n", j);
    }
    
    return 0;
}
