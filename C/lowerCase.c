#include <stdio.h>

#define DIFF 32

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char letter;
    
    for ( ; fscanf(in, "%c", &letter) == 1; ) {
        if ( letter > 64 && letter < 91 ) {
            letter += DIFF;
        }
        fprintf(out, "%c", letter);
    }
    fprintf(out, "\n");
    fclose(in);
    fclose(out);
    
    return 0;
}
