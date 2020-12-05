#include <stdio.h>

#define SIZE 17

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

void arraySort(int array[], int size) {
    int temp;
    
    for ( int i = 1; i != 0; ) {
        i = 0;
        for ( int j = 1; j < size; j++ ) {
            if ( array[j-1] > array[j] ) {
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
                i += 1;
            }
        }
    } 
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    //int start, end;
    
    //scanf("%d %d", &start, &end);
    arrayScan(in, array, SIZE);
        
    fclose(in);
    arraySort(array, SIZE);
    arrayPrint(out, array, SIZE);
    fclose(out);
    
    return 0;
}
