#include <stdio.h>

int placer(int number) {
    if ( number < 10 && number > 0 ) {
        return 1;
    }
    if ( number == 0 ) {
        return 1;
    }
    if ( number > -10 && number < 0 ) {
        return 2;
    }
    return 1 + placer(number/10);
}

int main() {
    int number;
    
    scanf("%d", &number);
    
    printf("%d\n", placer(number));
    
    return 0;
}
