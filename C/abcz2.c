#include <stdio.h>

int main() {
    int x;
    int isZulu = 1;
    
    scanf("%d", &x);
    
    if ( x % 2 == 0 ) {
        printf("alpha\n");
        isZulu = 0;
    }
    if ( x % 3 == 0 ) {
        printf("bravo\n");
        isZulu = 0;
    }
    if ( x % 5 == 0 ) {
        printf("charlie\n");
        isZulu = 0;
    }
    if ( isZulu ) {
        printf("zulu\n");
    }
    
    return 0;
}
