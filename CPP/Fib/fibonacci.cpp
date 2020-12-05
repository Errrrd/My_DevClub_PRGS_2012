#include "Fibonacci.h"

long long Fibonacci::fibonacci(int n) {
    long long fib;
    long long temp1, temp2;
    int k;
    
    fib = 0;
    temp1 = 1;
    k = -1;
    if ( n > 0 ) {
        for ( ; 0 < n; n-- ) {
            temp2 = temp1;
            temp1 = fib;
            fib = temp1 + temp2;
        }
    } else {
        for ( ; 0 > n; n++ ) {
            temp2 = temp1;
            temp1 = fib;
            fib = (temp1 + temp2);
            k *= -1;
        }
        fib *= k;
    }
    
    return fib;
}

Fibonacci::Fibonacci(int lastN) : lastN(lastN) {
    firstN = 0;
    it.it = firstN;
    it.fib = 0;
    first = 0;
    last = fibonacci(lastN);
}

Fibonacci::Fibonacci(int firstN, int lastN) : firstN(firstN), lastN(lastN) {
    it.it = firstN;
    it.fib = fibonacci(firstN);
    first = it.fib;
    last = fibonacci(lastN);
}

void Fibonacci::next() {
	It next;
    
    next.it = it.it + 1;
    next.fib = fibonacci(next.it);
    
    
    
    if ( next.it <= lastN + 1) {
        it.fib = next.fib;
        it.it = next.it;
    }
}

void Fibonacci::previous() {
	It previous;
    
    previous.it = it.it - 1;
    previous.fib = fibonacci(previous.it);
        
    if ( previous.it >= firstN - 1 ) {
        it.fib = previous.fib;
        it.it = previous.it;
    }
}

It Fibonacci::value() {
	It value;
    
    value.fib = it.fib;
    value.it = it.it;
    
    return value;
}

It Fibonacci::begin() {
    It begin;
    
    begin.it = firstN;
    begin.fib = first;
    
    
    return begin;
}

It Fibonacci::end() {
    It end;
    
    end.it = lastN;
    end.fib = last;
        
    return end;
}

void Fibonacci::operator++(int) {
	next();
}

void Fibonacci::operator--(int) {
	previous();
}

bool Fibonacci::operator<(It value) {
    return it.it < value.it;
}

bool Fibonacci::operator>(It value) {
    return it.it > value.it;
}

bool Fibonacci::operator<=(It value) {
    return it.it <= value.it;;
}

bool Fibonacci::operator>=(It value) {
    return it.it >= value.it;;
}

bool Fibonacci::operator==(It value) {
    return it.it == value.it;;
}

bool Fibonacci::operator!=(It value) {
        return !operator==(value);
}

long long Fibonacci::operator*() {
	return it.fib;
}
