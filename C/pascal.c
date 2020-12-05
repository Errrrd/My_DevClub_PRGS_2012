#include <stdio.h>

// int pas(int i, int j) {
    // if ( i == 0 ) {
        // return 0;
    // }
    // if ( j == 1 || j == i ) {
        // return 1;
    // }
    
    // return pas(i-1, j-1) + pas(i-1, j);
// }

int main() {
    int lines;
    
    scanf("%d", &lines);
    
    for ( int i = 1, j; i <= lines; i++ ) {
        x = 1;
        for ( j = 1; j < i; j++ ) {
            x = ...
            printf("%d ", x);
        }
        printf("%d\n", x);
    }
    
    return 0;
}

// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 5 1
// 1 6 15 15 6 1
// 1 7 21 30 21 7 1
// 1 8 28 51 51 28 8 1

x11 = 1
x21 = 1
x31 = 1
x41 = 1 ...
x22 = 1
x33 = 1
x32 = 2