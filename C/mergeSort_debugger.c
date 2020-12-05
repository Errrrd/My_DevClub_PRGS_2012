#include <stdio.h>

#define SIZE 50
#define LO 20
#define MID 32
#define HI 40

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
    int *end;
    
    end = array + mid;
    for (int i = 0, *alo = array + lo, *amid = array + mid; i < size; i++ ) {
        // for( int l = lo; l < mid; l++ ) {
            // printf("%d ", *alo);
            // alo += 1;
        // }
        // printf("\n");
        // for( int l = mid; l < hi; l++ ) {
            // printf("%d ", *amid);
            // amid += 1;
        // }
        // printf("\n");
        if ( *alo < *amid && alo < end ) {
            buffer[i] = *alo;
            alo += 1;
        } else {
            buffer[i] = *amid;
            amid += 1;
        }
        // printf("%d %d\n", alo, amid);
    }
    for ( int i = 0, j = lo; i < size; i++, j++ ) {
        // printf("%d ", buffer[i]);
        array[j] = buffer[i];
    }
    // printf("\n");
}

int main() {
    FILE *in = fopen("task1.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    arrayScan(in, array, SIZE);
    arrayPrint(out, array, SIZE);    
    fclose(in);
    merge(array, LO, MID, HI);
    arrayPrint(out, array, SIZE);
    fclose(out);
    
    return 0;
}
