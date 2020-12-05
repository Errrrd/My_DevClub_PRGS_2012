#include <stdio.h>

int main() {
    int total, rows, cols;
    int i, j, start;
    
    scanf("%d %d %d", &total, &rows, &cols);
    start = rows + 1;
    if (rows < cols ) {
        start = cols + 1;
    }
    for ( i = start; i <= total; i++ ) {
        for ( j = cols + 1; j < i; j++ ) {
            printf("%d ", j);
        }
        printf("%d\n", j);
    }
    
    return 0;
}
