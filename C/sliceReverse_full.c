#include <stdio.h>

#define SIZE 11

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

void sliceReverse(int array[], int lo, int hi) {
    int tmp;
    
    for ( ; lo < hi; ) {
        tmp = array[lo];
        array[lo] = array[hi];
        array[hi] = tmp;
        lo += 1;
        hi -= 1;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    int lo = 3, hi = 7;
    
    arrayScan(in, array, SIZE);
        
    fclose(in);
    sliceReverse(array, lo, hi);
    arrayPrint(out, array, SIZE);
    fclose(out);
    
    return 0;
}
