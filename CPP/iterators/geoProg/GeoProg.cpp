#include "GeoProg.h"

GeoProg::GeoProg(double first, int total, double step) : first(first), total(total), step(step) {
    it.it = 1;
    it.current = first;
    last = first;
    for( int i = 1; i < total; i++ ) {
        last *= step;
    }
}

GeoProg::GeoProg(int total, double step) : first(1), step(step), total(total) {
    it.it = 1;
    it.current = first;
    last = first;
    for( int i = 1; i < total; i++ ) {
        last *= step;
    }
}

void GeoProg::next() {
	It next;
    
    next.current = it.current * step;
    next.it = it.it + 1;
    if ( next.it <= total ) {
        it.current = next.current;
    }
    it.it = next.it;
}

void GeoProg::previous() {
	It previous;
    
    previous.it = it.it - 1;
    if ( step != 0 ) {
        previous.current = it.current / step;
        
        if ( previous.it >= 1 ) {
            it.current = previous.current;
            it.it = previous.it;
        } else {
            it.it = previous.it;
        }
    } else {
        it.it = previous.it;
        if ( previous.it == 1 ) {
            it.current = first;
            it.it = 1;
        }
    }
}

It GeoProg::value() {
	It value;
    
    value.current = it.current;
    value.it = it.it;
    
    return value;
}

It GeoProg::begin() {
    It begin;
    
    begin.current = first;
    begin.it = 1;
    
    return begin;
}

It GeoProg::end() {
    It end;
    
    end.current = last;
    end.it = total;
    
    return end;
}

void GeoProg::operator++(int) {
	next();
}

void GeoProg::operator--(int) {
	previous();
}

bool GeoProg::operator<(It value) {
    return it.it < value.it;
}

bool GeoProg::operator>(It value) {
    return it.it > value.it;
}

bool GeoProg::operator<=(It value) {
    return it.it <= value.it;;
}

bool GeoProg::operator>=(It value) {
    return it.it >= value.it;;
}

bool GeoProg::operator==(It value) {
    return it.it == value.it;;
}

bool GeoProg::operator!=(It value) {
        return !operator==(value);
}

double GeoProg::operator*() {
	return it.current;
}


