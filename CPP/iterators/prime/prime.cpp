#include "prime.h"

bool Prime::isPrime(int prime) {
    if ( prime < 2 ) {
        return 0;
    }
    if ( prime % 2 == 0 && prime != 2 ) {
        return 0;
    }
    for ( int i = 3; i*i <= prime; i += 2 ) {
        if ( prime % i == 0 ) {
            return 0;
        }
    }
    return 1;
}

int Prime::prime(int n) {
    int prime = 1;
    
    if ( n <= 0 || n > 1000000 ) {
        prime = 2;
    } else if ( n == 1 ) {
        prime = 2;
    } else {
        for ( int i = 2; i <= n; ) {
            prime += 2;
            if ( isPrime(prime) ) {
                i += 1;
            }
        }
    }
    
    return prime;
}

Prime::Prime(int lN) : lastN(lN) {
    if (lastN <= 0 ) {
        lastN = 1;
    }
    firstN = 1;
    it.it = 1;
    it.pr = 2;
    first = 2;
    last = prime(lastN);
}

Prime::Prime(int fN, int lN) : firstN(fN), lastN(lN) {
    if ( firstN > lastN ) {
        int tmp;
        
        tmp = firstN;
        firstN = lastN;
        lastN = tmp;
    }
    if (firstN > 0 ) {
        it.it = firstN;
        it.pr = prime(firstN);
        first = it.pr;
    } else {
        firstN = 1;
        it.it = 1;
        it.pr = 2;
        first = 2;
    }
    if (lastN > 1 ) {
        last = prime(lastN);
    } else {
        lastN = 2;
        last = 3;
    }
}

int Prime::getLast() const {
    return last;
}

int Prime::getFirst() const {
    return first;
}

void Prime::next() {
	It next;
    
    next.it = it.it + 1;
    next.pr = it.pr + 2;
    if ( it.it == 1 ) {
        next.pr = 3;
    } else {
        for ( ; !isPrime(next.pr); ) {
            next.pr += 2;
        }
    }
    if ( next.it <= lastN + 1 ) {
        it.pr = next.pr;
        it.it = next.it;
    }
}

void Prime::previous() {
	It previous;
    
    previous.it = it.it - 1;
    previous.pr = it.pr - 2;
    if ( previous.it <= 1 ) {
        previous.pr = 2;
    } else if ( previous.it == 2 ) {
        previous.pr = 3;
    } else {
        for ( ; !(isPrime(previous.pr)); ) {
            previous.pr -= 2;
        }
    }
    if ( previous.it >= firstN - 1 ) {
        it.pr = previous.pr;
        it.it = previous.it;
    }
}

It Prime::value() {
	It value;
    
    value.pr = it.pr;
    value.it = it.it;
    
    return value;
}

It Prime::begin() {
    It begin;
    
    begin.it = firstN;
    begin.pr = first;
        
    return begin;
}

It Prime::end() {
    It end;
    
    end.it = lastN;
    end.pr = last;
        
    return end;
}

void Prime::operator++(int) {
	next();
}

void Prime::operator--(int) {
	previous();
}

bool Prime::operator<(It value) {
    return it.it < value.it;
}

bool Prime::operator>(It value) {
    return it.it > value.it;
}

bool Prime::operator<=(It value) {
    return it.it <= value.it;;
}

bool Prime::operator>=(It value) {
    return it.it >= value.it;;
}

bool Prime::operator==(It value) {
    return it.it == value.it;;
}

bool Prime::operator!=(It value) {
        return !operator==(value);
}

int Prime::operator*() {
	return it.pr;
}
