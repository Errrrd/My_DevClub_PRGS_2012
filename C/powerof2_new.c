#include <stdio.h>

int main() {
    int power, number;
    
    scanf("%d", &power);
    
    number = 1;
    for ( int i = 0; i < power; i++ ) {
        printf("%d ", number);
        number += number;
    }
    printf("%d\n", number);
    
    return 0;
}
