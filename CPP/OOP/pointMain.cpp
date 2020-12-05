#include <iostream>

#include "Point.h"

using namespace std;

int main() {
	Point* a = new Point(3, 4);
	Point* b = new Point;
	
	cout << "Point a: " << *a << endl;
	cout << "Point b: " << *b << endl;

	if ( *a != *b ) {
		cout << "Distance is " << a->getDistance(*b) << endl;
	} else {
		cout << "Perfectly equal!" << endl;
	}


	return 0;
}
