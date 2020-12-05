#include <stdio.h>

int baseInPower(int dec, int base) {
    int powbase = 1;
    
    for ( ; dec >= base; dec /= base ) {
        powbase *= base;
    }
    return powbase;
}

void printOwerDec(int dec) {
    if ( dec < 10 ) {
        printf("%d", dec);
    } else {
        printf("%c", dec+55);
    }
}

int main() {
    int dec;
    int base;
    int remind;
    
    scanf("%d %d", &dec, &base);
    
    if ( dec < 0 ) {
        printf("-");
        dec = -dec;
    }
    
    remind = dec;
    for ( int bip = baseInPower(dec, base); bip >= base; bip /= base ) {
        int numeral = remind / bip;
        
        printOwerDec(numeral);
        remind %= bip;
    }
    printOwerDec(remind);
    printf("\n");
    
    return 0;
}
