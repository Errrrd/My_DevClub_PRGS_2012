#include <stdio.h>

int main() {
    int count;
    int i;
    
    scanf("%d", &count);
    
    for ( i = 1; i < count; i++ ) {
        printf("%d ", i);
    }
    printf("%d\n", i);
    
    return 0;
}
