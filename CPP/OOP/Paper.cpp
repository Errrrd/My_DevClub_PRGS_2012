#include <iostream>
#include "Paper.hpp"

using namespace std;

const string& Paper::getContent() const {
	return *content;
}

void Paper::show() const {
	cout << *content << endl;
}

void Paper::addContent(const string& text) {
	*content += text;
}
