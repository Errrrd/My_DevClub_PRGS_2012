void merge(int array[], int lo, int mid, int hi) {
    int size = hi - lo;
    int buffer[size];
    int *end;
    
    end = array + mid;
    for ( int i = 0, *alo = array + lo, *amid = array + mid; i < size; i++ ) {
        if ( *alo < *amid && alo < end ) {
            buffer[i] = *alo;
            alo += 1;
        } else {
            buffer[i] = *amid;
            amid += 1;
        }
    }
    for ( int i = 0, j = lo; i < size; i++, j++ ) {
        array[j] = buffer[i];
    }
}
