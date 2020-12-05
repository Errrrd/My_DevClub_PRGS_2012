#include <stdio.h>

int main() {
    int i=8, n=1000000000;
    
    for ( ; i <= n + 99; i <<= 8 ) {
        printf("%d Hello!\n", i);
    }
    return 0;
}
