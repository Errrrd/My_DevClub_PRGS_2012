#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Vector;

Vector vectorSum(Vector a, Vector b) {
    Vector sum;
    
    sum.x = a.x + b.x;
    sum.y = a.y + b.y;
    return sum;
}

Vector vectorDiff(Vector a, Vector b) {
    Vector diff;
    
    diff.x = a.x - b.x;
    diff.y = a.y - b.y;
    return diff;
}

void vectorIncrement(Vector *this, Vector other) {
    this->x += other.x;
    this->y += other.y;
}

void vectorDecrement(Vector *this, Vector other) {
    this->x -= other.x;
    this->y -= other.y;
}

int vectorEqual(Vector a, Vector b) {
    return a.x == b.x && a.y == b.y;
}

double vectorLen(Vector this) {
    return hypot(this.x, this.y);
}

void vectorPrint(Vector this) {
    printf("(%g, %g)", this.x, this.y);
}

int main() {
    Vector a = {4, 5};
    Vector b = {4, 5};
    Vector this = {3, 4};
    Vector other = {15, 18};
    vectorPrint(vectorSum(a, b));
    printf("\n");
    vectorPrint(a);
    printf("\n");
    vectorIncrement(&this, other);
    vectorPrint(this);
    printf("\n");
    vectorDecrement(&this, other);
    vectorPrint(this);
    printf("\n");
    printf("\n%d\n", vectorEqual(a, b));
    printf("%g\n", vectorLen(this));
    vectorPrint(this);
    
    return 0;
}
