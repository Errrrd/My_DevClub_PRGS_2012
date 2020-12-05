int powerOf2(int exponent) {
    int exp2 = 1;
    
    for( int i = 0; i < exponent; i++ ) {
        exp2 += exp2;
    }
    return exp2;
}
