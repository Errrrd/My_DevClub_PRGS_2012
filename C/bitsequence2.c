#include <stdio.h>

int main() {
    FILE *in1 = fopen("task.in", "r");
    FILE *in2 = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char bit;
    int quantnul = 0;
    int count = 0;
    
    for ( ; fscanf(in1, "%c", &bit) != EOF; ) {
        if ( bit == 48 ) {
            quantnul += 1;
        }
    }
    fclose(in1);
    for ( int i = 0; i < quantnul; i++ ) {
        fscanf(in2, "%c", &bit);
        if ( bit == 49 ) {
            count += 1;
        }
    }
    fclose(in2);
    fprintf(out, "%d\n", count);
    fclose(out);
    
    return 0;
}
