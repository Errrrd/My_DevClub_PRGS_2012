#include <stdio.h>

void func(int *x) {
    *x += 32;
}

int main(){
    int x = 10;
    int *p = &x;
    
    // p = &x; равнозначно...
    
    func(&x);
    printf("%d\n", x);
    
    
    return 0;
}