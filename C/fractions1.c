#include <stdio.h>

int main() {
    int div;
    int i, k, end, x;
    
    scanf("%d", &div);
    printf("0/%d ", div);
    for ( k = 1; k < div; k++ ) {
        end = div - (div - 1) / (k + 1);
        for ( i = div; i >= end ; i-- ) {
            if ( k == 1 ){
                printf("%d/%d ", k, i);
            } else if ( i % k != 0 ){
                printf("%d/%d ", k, i);
            } else {
                x = 1;
                for ( int j = 2; j >= k / 2; j++ ) {
                    if ( k % j == 0 && i % j == 0) {
                        x = j;
                    }
                }
                printf("%d/%d ", k/x, i/x);
            }
        }
    }
    printf("1/1\n");
    
    return 0;
}
