#include <stdio.h>

int main() {
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    if ( x % y == 0 && x != 0 ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
