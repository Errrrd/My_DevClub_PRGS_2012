void arrayReverse(int array[], int size) {
    int tmp;
    int last = size - 1;
    
    for ( int i = 0; i < last; i++, last-- ) {
        tmp = array[i];
        array[i] = array[last];
        array[last] = tmp;
    }
}