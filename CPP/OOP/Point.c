#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;

    void print() {
    	printf("(%g, %g)", x, y);	
    }
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
