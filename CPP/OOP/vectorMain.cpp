#include <iostream>
#include "Vector.cpp"

using namespace std;

int main() {
	Vector a(5, 5);
	Vector b(13, 14);
	Vector c = a + b;
	Vector d = a;

	d += b;
	cout << a;
	cout << "A" << a << endl;
	cout << "A(" << a.x << ", " << a.y << ')' << endl;
	cout << "B(" << b.x << ", " << b.y << ')' << endl;
	cout << "B len: " << b.len << endl;
	cout << "C(" << c.x << ", " << c.y << ')' << endl;
	cout << "D(" << d.x << ", " << d.y << ')' << endl;

	return 0;
}
