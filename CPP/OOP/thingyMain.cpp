#include <iostream>

#include "Thingy.cpp"

using namespace std;

void function(Thingy t) {
	cout << "lol" << endl; 
}

int main() {
	Thingy x;
	Thingy y;
	Thingy z = x;

	function(z);
	cout << "Thingies: " << Thingy::getQuantity() << endl;

	return 0;
}
