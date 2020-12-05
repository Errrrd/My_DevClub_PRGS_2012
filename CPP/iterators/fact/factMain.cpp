#include <iostream>

#include "Factorial.h"

using namespace std;

int main() {
	Factorial fact1(15);
    Factorial fact2(0, 12);
    Factorial fact3(5, 10);
    Factorial fact4(10, 3);

	for ( fact1.it = fact1.begin(); fact1 < fact1.end(); fact1++ ) {
		cout << *fact1 << " ";
	}
    cout << *fact1 << endl;
    for ( fact2.it = fact2.begin(); fact2 < fact2.end(); fact2++ ) {
		cout << *fact2 << " ";
	}
    cout << *fact2 << endl;
    for ( fact2.it = fact2.end(); fact2 > fact2.begin(); fact2-- ) {
		cout << *fact2 << " ";
	}
    cout << *fact2 << endl;
    for ( fact3.it = fact3.end(); fact3 > fact3.begin(); fact3-- ) {
		cout << *fact3 << " ";
	}
    cout << *fact3 << endl;
    for ( fact4.it = fact4.begin(); fact4 < fact4.end(); fact4++ ) {
		cout << *fact4 << " ";
	}
    cout << *fact4 << endl;
    
	return 0;
}
