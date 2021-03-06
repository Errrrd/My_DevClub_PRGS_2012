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

int partition(int array[], int start, int end) {
    int pivot = (start + end) / 2;
    int tmp;
    int lo = 0;
    int hi = end - 1;
    
    tmp = array[end];
    array[end] = array[pivot];
    array[pivot] = tmp;
    for ( int j = lo + 1; ; ) {
        if ( array[lo] > array[end] ) {
            if ( lo >= hi ) {
                pivot = lo+1;
                tmp = array[end];
                array[end] = array[pivot];
                array[pivot] = tmp;
                
                return pivot;
            }
            if ( array[j] <= array[end] ) {
                tmp = array[j];
                array[j] = array[hi];
                array[hi] = array[lo];
                array[lo] = tmp;
                lo += 1;
                hi -= 1;
                j += 1;
            } else {
                j += 1;
            }
        } else {
            lo += 1;
             if ( lo == end ) {
                pivot = end;
                tmp = array[end];
                array[end] = array[pivot];
                array[pivot] = tmp;
                return pivot;
            }
        }
    }
}

void quickSort(int array[], int lo, int hi) {
    int pivot = partition(array, lo, hi);
    
    if( lo < pivot - 1 ) {
        quickSort(array, lo, pivot-1);
    }
    if( pivot + 1 > hi ) {
        quickSort(array, pivot+1, hi);
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
    quickSort(array, 0, len-1);
    fclose(in);
    arrayPrint(out, array, len);
    fclose(out);
    
    return 0;
}
