#include "Paper.hpp"
#include "WritingUtencil.hpp"
#include "Pen.hpp"
#include "Exceptions.hpp"

Pen::Pen(unsigned int amount) {
	if ( amount > 100 ) {
		throw IncorrectInkAmount();
	}
	inkAmount = amount;
}

void Pen::write(Paper& paper, const std::string& text) {
	if ( inkAmount >= text.length() ) {
		WritingUtencil::write(paper, text);
		inkAmount -= text.length();
	} else {
		int deficient = text.length() - inkAmount;

		WritingUtencil::write(paper, text.substr(0, inkAmount));
		inkAmount = 0;

		throw OutOfInk(deficient);
	}
}

int Pen::getInkAmount() const { return inkAmount; }

void Pen::refill(unsigned int amount) {
	if ( inkAmount + amount > 100 ) {
		throw IncorrectInkAmount();
	}
	this->inkAmount += amount;
}
