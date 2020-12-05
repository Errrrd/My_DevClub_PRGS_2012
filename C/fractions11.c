#include <stdio.h>

int main() {
    int div;
    int end, i1, k1;
    int r = 0;
    
    scanf("%d", &div);
    printf("0/%d ", div);
    for ( int k = 1; k < div; k++ ) {
        end = div - (div - 1) / (k + 1);
        for ( int i = div; i >= end; i-- ) {
            i1 = i;
            k1 = k;
            if ( i % k == 0 ) {
                k1 = 1;
                i1 = i / k;
            }
            if ( i1 % 17 == 0 && k1 % 17 == 0 ) {
                k1 /= 17;
                i1 /= 17;
            }
            if ( i1 % 13 == 0 && k1 % 13 == 0 ) {
                k1 /= 13;
                i1 /= 13;
            }
            if ( i1 % 11 == 0 && k1 % 11 == 0 ) {
                k1 /= 11;
                i1 /= 11;
            }
            for ( ; i1 % 7 == 0 && k1 % 7 == 0; ) {
                k1 /= 7;
                i1 /= 7;
            }
            for ( ; i1 % 5 == 0 && k1 % 5 == 0; ) {
                k1 /= 5;
                i1 /= 5;
            }
            for ( ; i1 % 3 == 0 && k1 % 3 == 0; ) {
                k1 /= 3;
                i1 /= 3;
            }
            for ( ; i1 % 2 == 0 && k1 % 2 == 0; ) {
                k1 /= 2;
                i1 /= 2;
            }
            //printf("%d/%d ", k1, i1);
            float fk = k1;
            float fi = i1;
            float f = fk / fi;
            float max = 0;
            if ( f > max ) {
                max = f;
            } else {
                r += 1;
            }
            
            printf("%f ", f);
        }
    }
    printf("\nfail = %d\n", r);
    printf("1/1\n");
    
    return 0;
}
