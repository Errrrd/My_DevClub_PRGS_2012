#include <stdio.h>

int main() {
    FILE *in1 = fopen("taskbin.in", "r");
    FILE *in2 = fopen("taskbin.in", "r");
    FILE *out = fopen("task.out", "w");
    char bit;
    int quantnul = 0;
    int count = 0;
    
    for ( int i = 0; fscanf(in1, "%c", bit) == 1; i++ ) {
        if ( bit == 48 ) {
            quantnul += 1;
        }
        printf("%c", bit);
    }
    printf("\n");
    fclose(in1);
    for ( int i = 0; i < quantnul; i++ ) {
        fscanf(in2, "%c", bit);
        if ( bit == 49 ) {
            count += 1;
        }
    }
    fclose(in2);
    printf("%d\n", count);
    fprintf(out, "%d\n", count);
    fclose(out);
    
    return 0;
}
