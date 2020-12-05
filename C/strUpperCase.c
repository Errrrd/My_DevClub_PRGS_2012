void strUpperCase(char str[]) {
    for ( int i = 0, symbol = str[0]; symbol != 0; ) {
        if ( symbol > 96 && symbol < 123 ) {
            str[i] -= 32;
        }
        i += 1;
        symbol = str[i];
    }
}
