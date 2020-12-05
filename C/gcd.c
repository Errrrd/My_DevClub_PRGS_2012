int gcd(int a, int b) {
    int gcd;
    
    if ( a < 0 ) {
        a *= -1;
    }
    if ( b < 0 ) {
        b *= -1;
    }
    gcd = b;
    if ( a < b ) {
        gcd = a;
        a = b;
    }
    for (  ; a % gcd != 0 && b % gcd != 0; ) {
        gcd -= 1;
    }
    return gcd;
}
