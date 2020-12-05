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

int partition(int array[], int start, int end) {
    int pivot = (start + end) / 2;
    int tmp;
    int mark = start;
    
    tmp = array[end];
    array[end] = array[pivot];
    array[pivot] = tmp;
    for ( int i = start + 1; i <= end; ) {
        if ( array[end] < array[mark] ) {
            if ( array[end] > array[i] ){
                tmp = array[i];
                array[i] = array[mark];
                array[mark] = tmp;
                mark += 1;
                i = mark + 1;
            } else {
                i += 1;
            }
        } else {
            mark += 1;
            i += 1;
        }
        
    }
    tmp = array[mark];
    array[mark] = array[end];
    array[end] = tmp;
    return mark;
}

//printf("%d %d   ", mark, array[mark]);

void quickSort(int array[], int lo, int hi) {
    int pivot = partition(array, lo, hi);
    
    if( lo < pivot - 1 ) {
        quickSort(array, lo, pivot-1);
    }
    if( pivot + 1 < hi ) {
        quickSort(array, pivot+1, hi);
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = intScan(in);
    int array[len];
    
    arrayScan(in, array, len);
    arrayPrint(out, array, len);
    //quickSort(array, 0, len-1);
    partition(array, 0, 29);
    fclose(in);
    arrayPrint(out, array, len);
    fclose(out);
    
    return 0;
}
