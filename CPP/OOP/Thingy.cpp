#ifndef THINGY_CPP
#define THINGY_CPP

#include <iostream>

using namespace std;

class Thingy {
	private:
		static int quantity;

	public:
		Thingy() {
			quantity += 1;
		}

		Thingy(const Thingy& other) {
			cout << "Now copying..." << endl;
			quantity += 1;
		}

		static int getQuantity() {
			return quantity;
		}
};

int Thingy::quantity = 0;

#endif
