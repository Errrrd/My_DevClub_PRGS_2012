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




// ������� ������
// � ������� ��������� ��� ������������ ����������� ��� Point (����� �� ������������ ���������) ������������ x, y ���� double.
// ����� ����������� ��������� �������:

// void pointPrint(Point a) - ������ ����� � ���� (x, y). ��������������� �������� %g.
// int pointEqual(Point a, Point b) - ��������� ���� ����� �� ����������� (����� ��� �� �����).
// double pointDistance(Point a, Point b) - ���������� ���������� ����� ����� �������. ��������������� �������� hypot() �� ���������� math.h