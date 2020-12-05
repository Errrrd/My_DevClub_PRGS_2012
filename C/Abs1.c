#include <stdio.h>

void arrayAbs(int array[], int i) {
    if ( array[i] < 0 ) {
            array[i] *= -1;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size;
    
    fscanf(in, "%d", &size);
    int array[size];
    for ( int i = 0; i < size; i++ ) {
        fscanf(in, "%d", &array[i]);
        arrayAbs(array[], i);
        fprintf(out, "%d ", array[i]);
    }
    fscanf(in, "%d", &array[limit]);
    fclose(in);
    if ( array[limit] < 0 ) {
        array[limit] *= -1;
    }
    fprintf(out, "%d\n", array[limit]);
    fclose(out);
    
    return 0;
}
