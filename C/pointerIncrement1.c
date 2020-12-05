#include <stdio.h>

void pointerIncrement(int *value) {
    *value += 1;
}

int main() {
    int value = 77;
    pointerIncrement(*value);
        
    return 0;
}
