#include <stdio.h>
#include <math.h>

#define X 100
#define Y 100

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
    
    Point point = {X, Y};
    pointPrint(point);
    Point a = {X, Y};
    Point b = {X+30, Y+40};
    printf("point == a is %d\n", pointEqual(point, a));
    printf("a == b is %d\n", pointEqual(a, b));
    printf("Distance = %g\n", pointDistance(a, b));
    
    return 0;
}




// ������� ������
// � ������� ��������� ��� ������������ ����������� ��� Point (����� �� ������������ ���������) ������������ x, y ���� double.
// ����� ����������� ��������� �������:

// void pointPrint(Point a) - ������ ����� � ���� (x, y). ��������������� �������� %g.
// int pointEqual(Point a, Point b) - ��������� ���� ����� �� ����������� (����� ��� �� �����).
// double pointDistance(Point a, Point b) - ���������� ���������� ����� ����� �������. ��������������� �������� hypot() �� ���������� math.h