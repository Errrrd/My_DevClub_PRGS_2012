#include <stdio.h>

int powerOf2(int exponent) {
    return 1 << exponent;
}

int main() {
    int exponent = 10;
    
    printf("%d\n", powerOf2(exponent));
    
    return 0;
}
