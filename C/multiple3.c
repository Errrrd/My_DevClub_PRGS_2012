#include <stdio.h>

int main() {
    int count;
    int i;
    
    scanf("%d", &count);
    
    count -= count % 3;
    for ( i = 0; i < count; i += 3 ) {
        printf("%d ", i);
    }
    printf("%d\n", count);
    
    return 0;
}
