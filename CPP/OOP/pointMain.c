#include <iostream>
#include "Point.cpp"

using namespace std;

int main() {
	Point a;
	Point b(3, 4);

	a.print();
	if ( a.equals(b) ) {
		cout << " equals ";
	} else {
		cout << " is not equal to ";
	}
	b.print();
	cout << endl;
	cout << "Distance: " << a.distance(b) << endl;

	return 0;
}