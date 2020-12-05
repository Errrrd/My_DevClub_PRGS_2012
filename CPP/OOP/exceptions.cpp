#include <iostream>
#include <exception>
#include "exceptionClasses.cpp"

using namespace std;

void throwing2() {
	int x;

	cin >> x;

	if ( x == 42 ) {
		throw QuestionOfLife();	
	}
	cout << "You entered: " << x << endl;
}

void throwing() {
	try {
		throwing2();	
	} catch(InputError e) {
		cout << "Input error occured!" << endl;
	}
	
	cout << "blah..." << endl;
}

int main() {
	try {
		throwing();		
	} catch(QuestionOfLife) {
		cout << "What was the question?" << endl;
	} catch(...) {
		cout << "Unknown error!" << endl;
	}

	cout << "End of main" << endl;

	return 0;	
}
