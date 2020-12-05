#include <stdio.h>

#define A 1000
#define B 300000000

int main() {
    FILE *out = fopen("task.out", "w");
    unsigned long long a = 300000000;
    unsigned long long b = 1000;
    unsigned long long c = a * b;
    fprintf(out, "%llu\n", c);
    fclose(out);
    
    return 0;
}
