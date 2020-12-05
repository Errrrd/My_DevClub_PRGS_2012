#include <stdio.h>

#define SEQ 100

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len;
    
    len = 0;
    for ( int x; fscanf(in, "%d", &x) > 0 && len < SEQ; len++ );
    fclose(in);
    
    fprintf(out, "%d\n", len);
    fclose(out);
    
    return 0;
}
