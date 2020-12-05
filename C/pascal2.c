#include <stdio.h>

int pas(int i, int j) {
    if ( i == 0 ) {
        return 0;
    }
    if ( j == 1 || j == i ) {
        return 1;
    }
    
    return pas(i-1, j-1) + pas(i-1, j);
}

int main() {
    int lines;
    int j;
    
    scanf("%d", &lines);
    
    for ( int i = 1; i <= lines; i++ ) {
        for ( j = 1; j < i; j++ ) {
            printf("%d ", pas(i, j));
        }
        printf("%d\n", pas(i, j));
    }
    
    return 0;
}
