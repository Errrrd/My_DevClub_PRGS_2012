#ifndef PEN_HPP
#define PEN_HPP

#include "Paper.hpp"
#include "WritingUtencil.hpp"

class Pen : public WritingUtencil {
	private:
		unsigned long long inkAmount;

	public:
		Pen(unsigned int amount = 100);

		virtual void write(Paper&, const std::string&);

		int getInkAmount() const;

		void refill(unsigned int amount);
};

#endif
