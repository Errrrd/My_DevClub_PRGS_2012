#include "AriProg.h"

AriProg::AriProg(int first, int total, int step) : first(first), total(total), current(first), step(step) {
    last = first + step * (total - 1);
}

AriProg::AriProg(int total, int step) : first(0), step(step), total(total), current(0) {
    last = first + step * (total - 1);
}

void AriProg::next() {
	int next = current + step;
    
    if ( step > 0 ) {
        if ( next <= last ) {
            current = next;
        }
    } else {
        if ( next >= last ) {
            current = next;
        }
    }
}

void AriProg::previous() {
	int previous = current - step;
	
    if ( step > 0 ) {
        if ( previous >= first ) {
            current = previous; 
        }
    } else {
        if ( previous <= first ) {
            current = previous; 
        }
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

void AriProg::operator--(int) {
	previous();
}

bool AriProg::operator<(int value) {
	if ( step >= 0 ) {
        return current < value;
    }
    return current > value;
}

bool AriProg::operator>(int value) {
	if ( step >= 0 ) {
        return current > value;
    }
    return current < value;
}

bool AriProg::operator<=(int value) {
	if ( step >= 0 ) {
        return current <= value;
    }
    return current >= value;
}

bool AriProg::operator>=(int value) {
	if ( step >= 0 ) {
        return current >= value;
    }
    return current <= value;
}

bool AriProg::operator==(int value) {
        return current == value;
}

bool AriProg::operator!=(int value) {
        return !operator==(value);
}

int AriProg::operator*() {
	return current;
}

