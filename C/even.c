#include <stdio.h>

int main() {
    int count;
    int i;
    
    scanf("%d", &count);
    
    count -= 1;
    for ( i = 0; i < count; i += 2 ) {
        printf("%d ", i);
    }
    printf("%d\n", i);
    
    return 0;
}
