#include <iostream>

#include "AriProg.h"

using namespace std;

int main() {
	AriProg ariProg1(20);
    AriProg ariProg2(3, 35, 7);
    AriProg ariProg3(3, 10, -7);

	for ( ; ariProg1 < ariProg1.end(); ariProg1++ ) {
		cout << *ariProg1 << " ";
	}
    cout << *ariProg1 << endl;
    for ( ariProg2.begin(); ariProg2 < ariProg2.end(); ariProg2++ ) {
		cout << *ariProg2 << " ";
	}
    cout << *ariProg2 << endl;
    for ( ariProg3.begin(); ariProg3 < ariProg3.end(); ariProg3++ ) {
		cout << *ariProg3 << " ";
	}
    cout << *ariProg3 << endl;
    
	return 0;
}
