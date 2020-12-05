#include <iostream>

const int loops = 100000;

int main() {
	for ( int i = 1; i < loops; i++ ) {
		std::cout << i << " ";
	}
	std::cout << loops << std::endl;

	return 0;
}