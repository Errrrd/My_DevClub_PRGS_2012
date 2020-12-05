#include <stdio.h>

int average(int a, int b) {
    if ( (a <= 0) ^ (b <= 0) ) { 
        return (a + b) / 2;
    }
    return a / 2 + b / 2 + (a % 2 + b % 2) / 2;
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    printf("%d\n", average(a, b));
    return 0;
}