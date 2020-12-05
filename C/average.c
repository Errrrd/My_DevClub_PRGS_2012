unsigned int average(unsigned int a, unsigned int b) {
    if ( a > b ) {
        return (a - b) / 2 + b;
    }
    return (b - a) / 2 + a;
}
