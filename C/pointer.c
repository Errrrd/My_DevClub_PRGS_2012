#inclde <stdio.h>

void iFun(int *copy) {
    *copy += 1;
}

int main() {
    int x = 42;
    int *pointer;
    
    iFun(&x);
    pointer = x;
    printf("%d %p\n", x, pointer)
    
    return 0;
}
