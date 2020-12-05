#include <iostream>

#define LOOPS 1000000000

int main() {
	int counter = 0;

	for ( int i = 0; i < LOOPS; i++ ) {
		if ( i % 2 == 1 ) {
			counter += 1;
		} else {
			counter -= 1;
		}
	}
	std::cout << counter << std::endl;

	return 0;
}