#include <iostream>

#include "AriProg.h"

using namespace std;

int main() {
	AriProg ariProg1(20);
    AriProg ariProg2(3, 35, 7);

	for ( ; ariProg1 < ariProg1.end(); ariProg1++ ) {
		cout << *ariProg1 << " ";
	}
    cout << endl;
    for ( ariProg2.begin(); ariProg2 < ariProg2.end(); ariProg2++ ) {
		cout << *ariProg2 << " ";
	}
    cout << endl;
    
	return 0;
}
