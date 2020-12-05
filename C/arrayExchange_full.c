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

void arrayExchange(int array[], int size) {
    int tmp;
    
    for ( int i = 1; i < size; i += 2 ) {
        tmp = array[i];
        array[i] = array[i-1];
        array[i-1] = tmp;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    arrayScan(in, array, SIZE);
        
    fclose(in);
    arrayShiftLeft(array, SIZE);
    arrayPrint(out, array, SIZE);
    fclose(out);
    
    return 0;
}
