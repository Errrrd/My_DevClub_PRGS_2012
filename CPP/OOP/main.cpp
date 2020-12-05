#include <iostream>
#include "Paper.hpp"
#include "Pen.hpp"
#include "WritingUtencil.hpp"
#include "Exceptions.hpp"

using namespace std;

void hello(WritingUtencil& tool, Paper& paper) {
	tool.write(paper, "hello world!");
}

void shredder(Paper* paper) {
	delete paper;
}

int main() {
	Pen* pen;
	Paper* paper = new Paper;
	string text;

	try {
		int x;

		cin >> x;
		pen = new Pen(x);
	} catch(IncorrectInkAmount) {
		cout << "Incorrect amount of ink; please try again" << endl;
		return 0;
	}

	try {
		cin >> text;
		pen->write(*paper, text);
	} catch(OutOfInk e) {
		cout << "--debug: refilling by " << e.getAmount() << endl;
		pen->refill(e.getAmount());
		pen->write(*paper, text.substr(text.length() - e.getAmount()));
	}
	
	paper->show();
	shredder(paper);

	cout << "Ink left: " << pen->getInkAmount() << endl;
	delete pen;

	return 0;	
}
