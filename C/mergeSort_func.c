void merge(int array[], int lo, int mid, int hi) {
    int size = hi - lo;
    int buffer[size];
    
    for ( int i = 0, j = lo, k = mid; i < size; ) {
        if ( array[j] < array[k] && j < mid ) {
            buffer[i] = array[j];
            i += 1;
            j += 1;
        } else if ( k < hi ) {
            buffer[i] = array[k];
            i += 1;
            k += 1;
        }
        if ( k == hi && j < mid ) {
            buffer[i] = array[j];
            i += 1;
            j += 1;
        }
    }
    for ( int i = 0, j = lo; i < size; i++, j++ ) {
        array[j] = buffer[i];
    }
}

void mergeSort(int array[], int len) {
    int tmp;
    int last = len - len % 2;
    
    for ( int i = 1, j = 0; i < last; i += 2, j += 2 ) {
        if ( array[i] < array[j] ) {
            tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        }
    }
    if ( len > last ) {
        merge(array, last-2, last, len);
    }
    
    for ( int step = 2; step < len; ) {
        int start = 0;
        int mid = start + step;
        int end;
        
        step *= 2;
        end = start + step;
        for ( ; end < len; start += step, mid += step, end += step ) {
            merge(array, start, mid, end);
        }
        if ( mid < len ) {
            merge(array, start, mid, len);
        }
    }
}
