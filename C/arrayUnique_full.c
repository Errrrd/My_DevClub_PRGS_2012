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

int arrayUnique(int array[], int size) {
    int len = size - 1;
    
    for ( int i = 0; i < len; i++ ) {
        for ( int j = i + 1; j <= len; j++ ) {
            if ( array[i] == array[j] ) {
                for ( int k = j; k < len; k++ ) {
                    array[k] = array[k+1];
                }
                len -= 1;
                j -= 1;
            }
        }
    }
    return len + 1;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    int len;
    
    //scanf("%d %d", &start, &end);
    arrayScan(in, array, SIZE);
    fclose(in);
    len = arrayUnique(array, SIZE);
    arrayPrint(out, array, len);
    fprintf(out, "%d\n", len);
    fclose(out);
    
    return 0;
}
