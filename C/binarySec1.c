#include <stdio.h>

#define LIMIT 100000

int main() {
    FILE *in = fopen("taskbin.in", "r");
    FILE *out = fopen("task.out", "w");
    char bit[LIMIT];
    int quantnul = 0;
    int count = 0;

    fscanf(in, "%s", bit);
    printf("%s\n", bit);
    fclose(in);
    for ( int i = 0; *(bit+i) != 0; i++) {
        if ( *(bit+i) == 48 ) {
            quantnul += 1;
        }
        printf("%c_", bit[i]);
    }
    printf("\n");
    for ( int i = 0; i <= quantnul; i++) {
        if ( *(bit+i) == 49 ) {
            count += 1;
        }
    }
    fprintf(out, "%d\n", count);
    fclose(out);
    
    return 0;
}
