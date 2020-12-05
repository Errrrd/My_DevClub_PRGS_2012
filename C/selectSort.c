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

void selectSort(int array[], int size) {
    int min;
    int tmp;
    
    for ( int i = 0; i < size; i++ ) {
        min = i;
        for ( int j = i + 1; j < size; j++ ) {
            if ( array[j] <= array[min] ) {
                min = j;
            }
        }
        tmp = array[i];
        array[i] = array[min];
        array[min] = tmp;
    }
}

int main() {
    FILE *in = fopen("task3.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    arrayScan(in, array, SIZE);
    arrayPrint(out, array, SIZE);    
    fclose(in);
    selectSort(array, SIZE);
    arrayPrint(out, array, SIZE);
    fclose(out);
    
    return 0;
}
