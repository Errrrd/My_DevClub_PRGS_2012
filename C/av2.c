int average(int a, int b) {
    if ( a >= 0 && b <= 0 ) {
        return (a + b) / 2;
    }
    if ( b >= 0 && a <= 0 ) {
        return (a + b) / 2;
    }
    return a / 2 + b / 2 + (a % 2 + b % 2) / 2;
}
