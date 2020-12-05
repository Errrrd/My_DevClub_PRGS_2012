#include <stdio.h>

#define LEN 10

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[LEN];
    
    for ( int i = 0; i < LEN - 1; i++ ) {
        fscanf(in, "%d", &array[i]);
        fprintf(out, "%d ", array[i]);
    }
    fscanf(in, "%d", &array[LEN-1]);
    fclose(in);
    fprintf(out, "%d\n", array[LEN-1]);
    fclose(out);
    
    return 0;
}
