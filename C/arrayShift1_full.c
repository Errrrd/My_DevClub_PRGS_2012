#include <stdio.h>

#define SIZE 13
#define SHIFT -7

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

// 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17
// 13 14 15 16 17 0  1  2  3  4  5  6  7  8  9  10 11 12
// a5=a0
// a0=a13


void arrayShift(int array[], int size, int shift) {
    int shift1 = shift % size;
    int tmp;
    int j, i;
    
    if ( shift1 < 0 ) {
        shift1 += size;
    }
    tmp = array[shift1];
    for ( i = 0, j = shift1; i != shift1; ) {
        array[j] = array[i];
        j = i;
        if ( i < shift1 ) {
            i += size;
        }
        i -= shift1;
    }
    array[j] = tmp;
}


int main() {
    FILE *in = fopen("task1.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    arrayScan(in, array, SIZE);
    arrayPrint(out, array, SIZE);    
    fclose(in);
    arrayShift(array, SIZE, SHIFT);
    arrayPrint(out, array, SIZE);
    fclose(out);
    
    return 0;
}
