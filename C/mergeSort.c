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
    int *end;
    
    printf("%d ", 2);
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

void mergeSort(int array[], int lo, int hi) {
    int mid;
    
    if ( lo < hi ) {
        mid = (lo + hi) / 2;
        mergeSort(array, lo, mid);
        mergeSort(array, mid+1, hi);
        merge(array, lo, mid, hi+1);
        printf("%d ", 1);
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
    mergeSort(array, 0, len-1);
    fclose(in);
    arrayPrint(out, array, len);
    fclose(out);
    
    return 0;
}
