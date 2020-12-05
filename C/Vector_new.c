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
    this->x = vectorSum(*this, other).x;
    this->y = vectorSum(*this, other).y;
}

void vectorDecrement(Vector *this, Vector other) {
    this->x = vectorDiff(*this, other).x;
    this->y = vectorDiff(*this, other).y;
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
    Vector a = {5, 6};
    Vector b = {4, 5};
    Vector this = {3, 4};
    Vector other = {3, 3};
    
    printf("\nVector a = ");
    vectorPrint(a);
    printf("\nVector b = ");
    vectorPrint(b);
    printf("\nVector this = ");
    vectorPrint(this);
    printf("\nVector other = ");
    vectorPrint(other);
    printf("\nSum: ");
    vectorPrint(vectorSum(a, b));
    printf("\nIncrement this na other:");
    vectorIncrement(&this, other);
    vectorPrint(this);
    printf("\nDecrement this na other: ");
    vectorDecrement(&this, other);
    vectorPrint(this);
    printf("\n");
    printf("Equal a&b: %d\n", vectorEqual(a, b));
    printf("Len vector this: %g\n", vectorLen(this));
    
    return 0;
}
// Условие задачи
// С помощью известных вам инструментов реализовать тип Vector (вектор на координатной плоскости) с координатами x, y типа double. Также реализовать следующие функции:

// Vector vectorSum(Vector a, Vector b)
// Vector vectorDiff(Vector a, Vector b)
// void vectorIncrement(Vector *this, Vector other)
// void vectorDecrement(Vector *this, Vector other)
// int vectorEqual(Vector a, Vector b) - cравнение векторов по координатам
// double vectorLen(Vector this) – нахождение длины вектора. Воспользоваться функцией hypot() из библиотеки math.h
// void vectorPrint(Vector this) - печать вектора в виде (x, y). Воспользоваться шаблоном %g