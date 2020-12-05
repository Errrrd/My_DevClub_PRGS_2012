#include "factorial.h"

unsigned long long Factorial::factorial(unsigned int n) {
    unsigned long long factorial;
    
    factorial = 1;
    for ( int i = 2; i <= n; i++ ) {
        factorial *= i;
    }
    
    return factorial;
}

Factorial::Factorial(unsigned int lastN) : lastN(lastN) {
    firstN = 0;
    it.it = firstN;
    it.fact = 1;
    first = 1;
    last = factorial(lastN);
}

Factorial::Factorial(unsigned int firstN, unsigned int lastN) : firstN(firstN), lastN(lastN) {
    it.it = firstN;
    it.fact = factorial(firstN);
    first = it.fact;
    last = factorial(lastN);
}

void Factorial::next() {
	It next;
    
    next.it = it.it + 1;
    next.fact = it.fact * next.it;
    
    if ( next.it <= lastN + 1) {
        it.fact = next.fact;
        it.it = next.it;
    }
}

void Factorial::previous() {
	It previous;
    
    previous.it = it.it - 1;
    previous.fact = it.fact;
    if ( it.it > 0 ) { 
        previous.fact = it.fact / it.it;
    }    
    if ( previous.it >= firstN - 1 ) {
        it.fact = previous.fact;
        it.it = previous.it;
    }
}

It Factorial::value() {
	It value;
    
    value.fact = it.fact;
    value.it = it.it;
    
    return value;
}

It Factorial::begin() {
    It begin;
    
    begin.it = firstN;
    begin.fact = first;
        
    return begin;
}

It Factorial::end() {
    It end;
    
    end.it = lastN;
    end.fact = last;
        
    return end;
}

void Factorial::operator++(int) {
	next();
}

void Factorial::operator--(int) {
	previous();
}

bool Factorial::operator<(It value) {
    return it.it < value.it;
}

bool Factorial::operator>(It value) {
    return it.it > value.it;
}

bool Factorial::operator<=(It value) {
    return it.it <= value.it;;
}

bool Factorial::operator>=(It value) {
    return it.it >= value.it;;
}

bool Factorial::operator==(It value) {
    return it.it == value.it;;
}

bool Factorial::operator!=(It value) {
        return !operator==(value);
}

unsigned long long Factorial::operator*() {
	return it.fact;
}
