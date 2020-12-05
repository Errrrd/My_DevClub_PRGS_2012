#include <stdio.h>

int main() {
    int first;
    int step, total;
    
    scanf("%d %d %d", &first, &step, &total);
    
    for ( int i = 1; i < total; i++ ) {
        printf("%d ", first);
        first += step;
    }
    printf("%d\n", first);
    
    return 0;
}
