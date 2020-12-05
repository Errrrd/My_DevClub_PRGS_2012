#include "AriProg.h"

AriProg::AriProg(double first, int total, double step) : first(first), total(total), current(first), step(step) {
    last = first + step * (total - 1);
}

AriProg::AriProg(int total, double step) : first(0), step(step), total(total), current(0) {
    last = first + step * (total - 1);
}

void AriProg::next() {
	int next = current + step;

	if ( next <= last ) {
		current = next;
	}
}

void AriProg::previous() {
	int previous = current - step;
	
	if ( previous >= first ) {
		current = previous; 
	}
}

void AriProg::rewind() {
	current = first;
}

int AriProg::value() {
	return current;
}

int AriProg::begin() {
	return first;
}

int AriProg::end() {
	return last;
}

void AriProg::operator++(int) {
	next();
}

bool AriProg::operator<(int value) {
	return current < value;
}

int AriProg::operator*() {
	return current;
}

