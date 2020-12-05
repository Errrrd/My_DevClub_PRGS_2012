#include <stdio.h>

int main() {
    int plain1, encrypted1;
    int plain2, encrypted2;
    int length;
    int number, a, b;
    
    scanf("%d %d %d %d %d %d", &plain1, &encrypted1, &plain2, &encrypted2, &length, &number);
    
    a = (encrypted2 - encrypted1) / (plain2 - plain1);
    b = encrypted1 - a * plain1;
    number -= b;
    for ( ; 1 < length; length-- ) {
        printf("%d ", number/a);
        scanf("%d", &number);
        number -= b;
    }
    printf("%d\n", number/a);
    
    return 0;
}
