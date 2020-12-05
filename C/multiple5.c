#include <stdio.h>

int main() {
    int counter;
    int i;
    
    scanf("%d", &counter);
    
    counter -= 4;
    for ( i = 0; i < counter; i += 5 ) {
        printf("%d ", i);
    }
    printf("%d\n", i);
    
    return 0;
}
