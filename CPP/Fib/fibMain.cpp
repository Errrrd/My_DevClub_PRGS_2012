#include <iostream>

#include "Fibonacci.h"

using namespace std;

int main() {
	Fibonacci fib1(50);
    Fibonacci fib2(-5, 10);
    Fibonacci fib3(-7, -3);
    Fibonacci fib4(7, 15);

	for ( fib1.it = fib1.begin(); fib1 < fib1.end(); fib1++ ) {
		cout << *fib1 << " ";
	}
    cout << *fib1 << endl;
    for ( fib2.it = fib2.begin(); fib2 < fib2.end(); fib2++ ) {
		cout << *fib2 << " ";
	}
    cout << *fib2 << endl;
    for ( fib3.it = fib3.begin(); fib3 < fib3.end(); fib3++ ) {
		cout << *fib3 << " ";
	}
    cout << *fib3 << endl;
    for ( fib4.it = fib4.end(); fib4 > fib4.begin(); fib4-- ) {
		cout << *fib4 << " ";
	}
    cout << *fib4 << endl;
    for ( fib4.it = fib4.begin(); fib4 < fib4.end(); fib4++ ) {
		cout << *fib4 << " ";
	}
    cout << *fib4 << endl;
    
	return 0;
}
