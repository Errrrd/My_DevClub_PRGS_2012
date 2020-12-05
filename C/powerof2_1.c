int powerOf2(int exponent) {
    if ( exponent == 0 ) {
        return 1;
    }
    return 2 * powerOf2(exponent-1);
}
