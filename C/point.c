#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

void pointPrint(Point a) {
    printf("(%g, %g)", a.x, a.y);
}

int pointEqual(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}

double pointDistance(Point a, Point b) {
    return hypot(a.x-b.x, a.y-b.y);
}

int main() {
    Point a = {0, 0};
    Point b = {-100, -100};
    pointPrint(a);
    pointEqual(a, b);
    pointDistance(a, b);
    
    return 0;
}




// Условие задачи
// С помощью известных вам инструментов реализовать тип Point (точка на координатной плоскости) координатами x, y типа double.
// Также реализовать следующие функции:

// void pointPrint(Point a) - печать точки в виде (x, y). Воспользоваться шаблоном %g.
// int pointEqual(Point a, Point b) - сравнение двух точек по координатам (равны или не равны).
// double pointDistance(Point a, Point b) - нахождение расстояния между двумя точками. Воспользоваться функцией hypot() из библиотеки math.h