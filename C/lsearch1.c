#include <stdio.h>

#define SIZE 123

int intScan(FILE *in) {
    int needle;
    
    fscanf(in, "%d", &needle);
    return needle;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int needle = intScan(in);
    int array[SIZE];
    
    for ( int i = 0; i < SIZE && i < 100; i++ ) {
        fscanf(in, "%d", &array[i]);
        if ( needle == array[i] ) {
            fprintf(out, "%d\n", i);
            fclose(in);
            fclose(out);
            return 0;
        }
    }
    fclose(in);
    fprintf(out, "-1\n");
    fclose(out);
    
    return 0;
}
