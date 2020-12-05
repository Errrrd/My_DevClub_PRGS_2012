#include <stdio.h>

int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    int div;
    int end, div1;
    
    scanf("%d", &div);
    printf("0/1 ");
    if ( div == 0 ) {
        return 0;
    }
    for ( int i = 1; i < div; i++ ) {
        end = div - (div - 1) / (i + 1);
        for ( int j = div; j >= end; j-- ) {
            div1 = gcd(j, i);
            printf("%d/%d ", i/div1, j/div1);
        }
        printf("\n");
    }
    printf("1/1\n");
    
    return 0;
}
