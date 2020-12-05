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

void arrayShiftRight(int array[], int size) {
    int tmp;
    int last = size - 1;
    
    for ( tmp = array[last]; last > 0; last-- ) {
        array[last] = array[last-1];
    }
    array[0] = tmp;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    arrayScan(in, array, SIZE);
        
    fclose(in);
    arrayShiftRight(array, SIZE);
    arrayPrint(out, array, SIZE);
    fclose(out);
    
    return 0;
}
