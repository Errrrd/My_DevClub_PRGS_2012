#include <stdio.h>

int intScan(FILE *in) {
    int number;
    
    fscanf(in, "%d", &number);
    return number;
}

int arrayScan(FILE *in, int array[], int limit) {
    int size = 0;
    
    for ( ; size < limit && fscanf(in, "%d", &array[size]) == 1; size++ );
    return size;
}

void arrayPrint(FILE *out, int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

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
    
    if ( len > 1 ) {
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
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = intScan(in);
    int array[len];
    
    arrayScan(in, array, len);
    mergeSort(array, len);
    fclose(in);
    arrayPrint(out, array, len);
    fclose(out);
    
    return 0;
}
