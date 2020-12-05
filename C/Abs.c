#include <stdio.h>

int intScan(FILE *in) {
    int size;
    
    fscanf(in, "%d", &size);
    return size;
}

void arrayAbs(int array[], int i) {
    if ( array[i] < 0 ) {
            array[i] *= -1;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = intScan(in);
    int limit = size - 1;
    int array[size];
    
    for ( int i = 0; i < limit; i++ ) {
        fscanf(in, "%d", &array[i]);
        arrayAbs(array, i);
        fprintf(out, "%d ", array[i]);
    }
    fscanf(in, "%d", &array[limit]);
    fclose(in);
    arrayAbs(array, limit);
    fprintf(out, "%d\n", array[limit]);
    fclose(out);
    
    return 0;
}
