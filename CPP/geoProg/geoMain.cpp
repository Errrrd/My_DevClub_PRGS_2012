#include <iostream>

#include "GeoProg.h"

using namespace std;

int main() {
	GeoProg geoProg1(20);
    GeoProg geoProg2(1, 10, 3);
    GeoProg geoProg3(2, 11, -3);
    GeoProg geoProg4(1024, 20, 0.5);
    GeoProg geoProg5(1, 10, 0);
    GeoProg geoProg6(1024, 20, -0.5);
    GeoProg geoProg7(3, 10, 1);

	for ( geoProg1.it = geoProg1.begin(); geoProg1 < geoProg1.end(); geoProg1++ ) {
		cout << *geoProg1 << " ";
	}
    cout << *geoProg1 << endl;
    for ( geoProg2.it = geoProg2.begin(); geoProg2 <= geoProg2.end(); geoProg2++ ) {
		cout << *geoProg2 << " ";
	}
    cout << endl;
    for ( geoProg3.it = geoProg3.begin(); geoProg3 < geoProg3.end(); geoProg3++ ) {
		cout << *geoProg3 << " ";
	}
    cout << *geoProg3 << endl;
    for ( geoProg4.it = geoProg4.end(); geoProg4 > geoProg4.begin(); geoProg4-- ) {
		cout << *geoProg4 << " ";
	}
    cout << *geoProg4 << endl;
    for ( geoProg4.it = geoProg4.begin(); geoProg4 < geoProg4.end(); geoProg4++ ) {
		cout << *geoProg4 << " ";
	}
    cout << *geoProg4 << endl;
     for ( geoProg5.it = geoProg5.begin(); geoProg5 < geoProg5.end(); geoProg5++ ) {
		cout << *geoProg5 << " ";
	}
    cout << *geoProg5 << endl;
    for ( geoProg5.it = geoProg5.end(); geoProg5 > geoProg5.begin(); geoProg5-- ) {
		cout << *geoProg5 << " ";
	}
    cout << *geoProg5 << endl;
    for ( geoProg6.it = geoProg6.begin(); geoProg6 < geoProg6.end(); geoProg6++ ) {
		cout << *geoProg6 << " ";
	}
    cout << *geoProg6 << endl;
    for ( geoProg6.it = geoProg6.end(); geoProg6 > geoProg6.begin(); geoProg6-- ) {
		cout << *geoProg6 << " ";
	}
    cout << *geoProg6 << endl;
    for ( geoProg7.it = geoProg7.begin(); geoProg7 < geoProg7.end(); geoProg7++ ) {
		cout << *geoProg7 << " ";
	}
    cout << *geoProg7 << endl;
    for ( geoProg7.it = geoProg7.end(); geoProg7 > geoProg7.begin(); geoProg7-- ) {
		cout << *geoProg7 << " ";
	}
    cout << *geoProg7 << endl;
    
	return 0;
}

