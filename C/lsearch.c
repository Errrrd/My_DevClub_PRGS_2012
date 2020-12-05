#include <stdio.h>

#define SIZE 100

int intScan(FILE *in) {
    int needle;
    
    fscanf(in, "%d", &needle);
    return needle;
}

int arrayScan(FILE *in, int array[], int limit) {
    int size = 0;
    
    for ( ; size < limit && fscanf(in, "%d", &array[size]) == 1; size++ );
    return size;
}

int arraySearch(int array[], int size, int needle) {
    for ( int i = 0; i < size; i++ ) {
        if ( needle == array[i] ) {
            return i;
        }
    }
    return -1;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int needle = intScan(in);
    int array[SIZE];
    int size = arrayScan(in, array, SIZE);
    
    fclose(in);
    fprintf(out, "%d\n", arraySearch(array, size, needle));
    fclose(out);
    
    return 0;
}
