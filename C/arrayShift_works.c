// Условие задачи
// Написать функцию:
// void arrayShift(int array[], int size, int shift)
// Реализовать циклический сдвиг массива на shift элементов вправо. Максимизировать производительность при оптимальном использовании памяти.
// Требуемая сложность: O(N)

#include <stdio.h>

#define SIZE 1
#define SHIFT 1

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

// 0  1  2  3  4  5  6  7  8  9  10 11 12
// 8  9  10 11 12 0  1  2  3  4  5  6  7  
// b0-a0
// a0-a8
// b1-a1
// a1-a9
// b2-a2
// a2-a10
// b3-a3
// a3-a11
// b4-a4
// a4-a12
// a10-a5
// a11-a6
// a12-a7
// a5-b0
// a6-b1
// a7-b2
// a8-b3
// a9-b4
// 0  1  2  3  4  5  6  7  8  9  10 11 12
// 5  6  7  8  9  10 11 12 0  1  2  3  4
// b0-a8
// a8-a0
// b1-a9
// a9-a1
// b2-a10
// a10-a2
// b3-a11
// a11-a3
// b4-a12
// a12-a4
// a0-a5
// a1-a6
// a2-a7
// a3-b0
// a4-b1
// a5-b2
// a6-b3
// a7-b4

void arrayShift(int array[], int size, int shift) {
    int half = size / 2;
    int buffer[half];
    int i, j, k;
    
    shift %= size;
    if ( shift < 0 ) {
        shift += size;
    }
    if ( shift <= half ) {
        for ( i = size - 1, j = shift - 1, k = i - shift; j >= 0; i--, j--, k-- ) {
            buffer[j] = array[i];
            array[i] = array[k];
        }
        for ( ; i >= shift; i--, k-- ) {
            array[i] = array[k];
        }
        for ( j = shift - 1; i >= 0; i--, j-- ) {
            array[i] = buffer[j];
        }
    } else {
        int end = size - shift;
        
        for ( i = 0, j = 0, k = end; j < end; i++, j++, k++ ) {
            buffer[j] = array[i];
            array[i] = array[k];
        }
        for ( ; i < shift; i++, k++ ) {
            array[i] = array[k];
        }
        for ( j = 0; i < size; i++, j++ ) {
            array[i] = buffer[j];
        }
    }
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
