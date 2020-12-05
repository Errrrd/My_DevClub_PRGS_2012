#include <stdio.h>

#define DIFF 32
#define ALF 26

void arrayNull(int array[], int size) {    
    for ( int i = 0; i < size; i++ ) {
        array[i] = 0;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int counter[ALF];

    arrayNull(counter, ALF);
    for ( char letter; fscanf(in, "%c", &letter) == 1; ) {
        if ( letter > 64 && letter < 91 ) {
            letter += DIFF;
        }
        if ( letter > 96 && letter < 123 ) {
            counter[letter - 97] += 1;
        }
    }
    fclose(in);
    for ( int i = 0; i < ALF; i++ ) {
        if ( counter[i] ) {
            fprintf(out, "%c %d\n", i+97, counter[i]);
        }
    }
    fclose(out);
    
    return 0;
}
