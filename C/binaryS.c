#include <stdio.h>

#define LIMIT 10000

int arrayScan(FILE *in, char array[], int limit) {
    int quantnul = 1;
    
    for ( int size = 0; size < limit && fscanf(in, "%c", &array[size]) != EOF; size++ ) {
        if ( array[size] == '0' ) {
            quantnul += 1;
        }
    }
    
    return quantnul;
}

int main() {
    FILE *in = fopen("taskbin.in", "r");
    FILE *out = fopen("task.out", "w");
    char bit[LIMIT];
    int quantnul = arrayScan(in, bit, LIMIT);
    int count = 0;
    
    fclose(in);
    for ( int i = 0; i < quantnul; i++) {
        if ( bit[i] == '1' ) {
            count += 1;
        }
    }
    fprintf(out, "%d\n", count);
    fclose(out);
    
    return 0;
}
