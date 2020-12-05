#include <iostream>

#include "Prime.h"

using namespace std;

int main() {
	Prime pr1(20);
    Prime pr2(3, 15);
    Prime pr3(5, 25);
    Prime pr4(6, 28);
    Prime pr5(18);
    
    cout << pr1.getLast() << endl;
    cout << pr2.getLast() << endl;
    cout << pr3.getLast() << endl;
    cout << pr4.getLast() << endl;
    cout << pr5.getLast() << endl;
    
    cout << pr1.getFirst() << endl;
    cout << pr2.getFirst() << endl;
    cout << pr3.getFirst() << endl;
    cout << pr4.getFirst() << endl;
    cout << pr5.getFirst() << endl;
    
	for ( pr1.it = pr1.begin(); pr1 < pr1.end(); pr1++ ) {
		cout << *pr1 << " ";
	}
    cout << *pr1 << endl << endl;
    for ( pr3.it = pr3.begin(); pr3 < pr3.end(); pr3++ ) {
		cout << *pr3 << " ";
	}
    cout << *pr3 << endl << endl;
    for ( pr3.it = pr3.end(); pr3 > pr3.begin(); pr3-- ) {
		cout << *pr3 << " ";
	}
    cout << *pr3 << endl << endl;
    for ( pr3.it = pr3.end(); pr3 > pr3.begin(); pr3-- ) {
		cout << *pr3 << " ";
	}
    cout << *pr3 << endl << endl;
    for ( pr4.it = pr4.begin(); pr4 < pr4.end(); pr4++ ) {
		cout << *pr4 << " ";
	}
    cout << *pr4 << endl << endl;
    for ( pr5.it = pr5.begin(); pr5 < pr5.end(); pr5++ ) {
		cout << *pr5 << " ";
	}
    cout << *pr5 << endl << endl;
    
	return 0;
}
