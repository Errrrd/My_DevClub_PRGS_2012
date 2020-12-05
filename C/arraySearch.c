int arraySearch(int array[], int size, int needle) {
    for ( int i = 0; i < size; i++ ) {
        if ( needle == array[i] ) {
            return i;
        }
    }
    return -1;
}
