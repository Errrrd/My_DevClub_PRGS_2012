#include <stdio.h>

#define SIZE 10

void arrayRead(FILE *in, int array[]) {
    for ( int i = 0; i < SIZE; i++ ) {
        fscanf(in, "%d", &array[i]);
    }
}

void arrayPrint(FILE *out, int array[]) {
    int last = SIZE - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    
    arrayRead(in, array);
    fclose(in);
    arrayPrint(out, array);
    fclose(out);
    
    return 0;
}
