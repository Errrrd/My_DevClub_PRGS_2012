#include <stdio.h>

#define SIZE 25

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

void insertSort(int array[], int len) {
    int max;
    int i, j;
   
    for ( i = len - 1; i > 0; i-- ) {
        for ( j = 0; j < i; j++ ) {
            if( array[i] < array[j] ) {
                max = array[j];
                array[j] = array[i];
                array[i] = max;
            }
        }
    }
}

int main() {
    FILE *in = fopen("task3.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    arrayScan(in, array, SIZE);
    arrayPrint(out, array, SIZE);    
    fclose(in);
    insertSort(array, SIZE);
    arrayPrint(out, array, SIZE);
    fclose(out);
    
    return 0;
}
