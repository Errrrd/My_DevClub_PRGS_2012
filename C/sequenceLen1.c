#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int x;
    int j;
    
    for ( j=0; fscanf(in, "%d", &x) > 0 && j < 100; j++ ) {
    }
    fclose(in);
    
    fprintf(out, "%d\n", j);
    fclose(out);
    
    return 0;
}
