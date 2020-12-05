#include <cmath>
#include <iostream>

using namespace std;

class Vector {
    public:
        double x, y;
        double len;

        Vector() : x(0), y(0), len(0) {}

        Vector(double x, double y) : x(x), y(y) {
            len = hypot(x, y);
        }

        void operator+= (Vector other) {
            x += other.x;
            y += other.y;
        }

        Vector operator+ (Vector other) {
            Vector sum = *this;

            sum += other;
            return sum;
        }
};

ostream& operator<< (ostream& out, Vector v) {
    out << ;
    return out;
}


// void vectorDecrement(Vector *this, Vector other) {
//     this->x -= other.x;
//     this->y -= other.y;
// }

// int vectorEqual(Vector a, Vector b) {
//     return a.x == b.x || a.y == b.y;
// }

// void vectorPrint(Vector this) {
//     printf("(%g, %g)", this.x, this.y);
// }
