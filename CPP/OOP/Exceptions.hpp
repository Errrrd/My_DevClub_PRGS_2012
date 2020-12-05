#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

class IncorrectInkAmount {};

class OutOfInk {
	private:
		int amount;
	public:
		OutOfInk(int amount) : amount(amount) {}

		int getAmount() {
			return amount;
		}
};

#endif
