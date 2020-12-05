#include "Thingy.cpp"

class Thingling : public Thingy {
	private:
		static int quantity;

	public:
		Thingling() {
			quantity += 1;
			Thingy::quantity -= 1;
		}

		static int getQuantity() {
			return quantity;
		}
};

int Thingling::quantity = 0;
