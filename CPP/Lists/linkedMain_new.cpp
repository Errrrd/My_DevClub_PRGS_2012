#include <iostream>

#include "linkedList_new.h"

#define LOOPS 100000000

using namespace std;

int main() {
	LinkedList<char> list;
    
    string str = "1234567890---=!@#$%^&*()_+~QWERTYUIOP{}ASDFGHJKL:qwwertyuiop[asdfghfjkl";

    for ( int i = 0; str[i] != 0; i++ ) {
		list.push_back(str[i]);
    }
    list.push_front('a');
    // for ( LinkedList<char>::iterator it=list.begin() ; it != list.end(); it++ ) {
        // cout << *it << " ";
    // }

  cout << endl;
    
    

	return 0;
}
