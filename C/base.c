#include <stdio.h>

int baseInPower(unsigned int dec, unsigned int base) {
    int powbase = 1;
    
    for ( ; dec >= base; dec /= base ) {
        powbase *= base;
    }
    return powbase;
}

int main() {
    unsigned int dec;
    unsigned int base;
    unsigned int remind;
    
    scanf("%d %d", &dec, &base);
    
    remind = dec;
    for ( int bip = baseInPower(dec, base); bip >= base; bip /= base ) {
        printf("%d", remind/bip);
        remind %= bip;
    }
    printf("%d\n", remind);
    
    return 0;
}
