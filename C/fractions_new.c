#include <stdio.h>

int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    int div;
    int end;
    int up, down;
    
    scanf("%d", &div);
    printf("0/1 ");
    for ( int i = 1; i < div; i++ ) {
        end = div - (div - 1) / (i + 1);
        for ( int j = div; j > end; j-- ) {
            int gcd1 = gcd(i, j);
            
            up = i / gcd1;
            down = j / gcd1;
            printf("%d/%d ", up, down);
        }
    }
    printf("1/1\n");
    
    return 0;
}
