#include <iostream>

#include "arrayList.h"

#define LOOPS 100

using namespace std;

int main() {
	ArrayList<int> list;

	for ( int i = 0; i < LOOPS; i++ ) {
		list.push_back(i);
	}
    for ( ArrayList<int>::iterator it = list.begin() ; it < list.end(); it++ ) {
        cout << *it <<" ";
    }
    cout << endl;

	return 0;
}
