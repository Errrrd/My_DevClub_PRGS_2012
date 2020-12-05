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
        printf("%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
    printf("%d\n", array[last]);
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
        if( k == hi && j < mid ){
            buffer[i] = array[j];
            i += 1;
            j += 1;
        }
    }
    for ( int i = 0, j = lo; i < size; i++, j++ ) {
        array[j] = buffer[i];
    }
}

void mergeSort(int array[], int lo, int hi) {
    int tmp;
    int last = hi - hi%2;
    
    for ( int i = 1, j = 0; i < last; i += 2, j += 2 ) {
        if ( array[i] < array[j] ) {
            tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        }
    }
    if ( hi > last ) {
        merge(array, last-2, last, hi);
    }
    for (int step = 2; step < hi; ) {
        int start = 0;
        int mid = start + step;
        int end;
    
        step *= 2;
        last = hi - hi%step;
        end = start + step;
        for ( ; end < hi; start += step, mid += step, end += step ) {
            merge(array, start, mid, end);
            //printf("%d %d %d %d,  ", start, mid, end, step);
        }
        if ( mid < hi ) { 
        merge(array, start, mid, hi);
        }
        printf("\n");
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = intScan(in);
    int array[len];
    
    printf("%d\n", len);
    printf("%d\n", arrayScan(in, array, len));
    arrayPrint(out, array, len);
    mergeSort(array, 0, len);
    fclose(in);
    arrayPrint(out, array, len);
    fclose(out);
    
    return 0;
}
