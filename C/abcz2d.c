#include <stdio.h>

int main() {
    int x;
    
    scanf("%d", &x);
    
    if ( x % 2 == 0 ) {
        printf("alpha\n");
    }
    if ( x % 3 == 0 ) {
        printf("bravo\n");
    }
    if ( x % 5 == 0 ) {
        printf("charlie\n");
    }
    if ( x % 5 != 0 && x % 3 != 0 && x % 2 != 0) {
        printf("zulu\n");
    }

    return 0;
}
