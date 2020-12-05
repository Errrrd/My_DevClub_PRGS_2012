#include <stdio.h>

#define LEN 10

void arrayZeroFill(int array[], int size) {
    for ( int i = 0; i < size-1; i++ ) {
        array[i] = 0;
    }
}

int main() {
    //FILE *in = fopen("task.in", "r");
    //FILE *out = fopen("task.out", "w");
    int size = 10;
    int array[size];
    
    arrayZeroFill(array, size);
    for ( int i = 0; i < size - 1; i++ ) {
        //fscanf(in, "%d", &array[i]);
        //fprintf(out, "%d ", array[i]);
        printf("%d ", array[i]);
    }
    //fscanf(in, "%d", &array[LEN-1]);
    //fclose(in);
    //fprintf(out, "%d\n", array[LEN-1]);
    //fclose(out);
    
    return 0;
}
