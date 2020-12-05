#include <stdio.h>

#define SIZE 21

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

void sliceShiftLeft(int array[], int start, int end) {
    int tmp;
    
    if ( start < end ) {
        tmp = array[start];
        for ( ; start < end; start++ ) {
            array[start] = array[start+1];
        }
        array[end] = tmp;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    int start, end;
    
    scanf("%d %d", &start, &end);
    arrayScan(in, array, SIZE);
        
    fclose(in);
    sliceShiftRight(array, start, end);
    arrayPrint(out, array, SIZE);
    fclose(out);
    
    return 0;
}
