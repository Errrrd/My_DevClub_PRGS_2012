#include <stdio.h>

int main() {
    int count;
    int i;
    
    scanf("%d", &count);
    
    for ( i = 1; i < count - 1; ) {
        printf("%d ", i);
        i += 2;
    }
    printf("%d\n", i);
    
    return 0;
}
