#include <cstdlib>
#include <cstddef>
#include <exception>

#include "arrayList.h"

using namespace std;

template<class T>
ArrayList<T>::ArrayList() : len(0), capacity(step), content(NULL) {
	resize(step);
}

template<class T>
ArrayList<T>::~ArrayList() {
	free(content);
}

template<class T>
void ArrayList<T>::append(T value) {
	if ( len + 1 == capacity ) {
		size_t newCapacity = capacity * multiplier;

		resize(newCapacity);
		capacity = newCapacity;	
	}

	content[len] = value;
	len += 1;
}

template<class T>
T ArrayList<T>::pop() {
	size_t newLen = len - 1;
	size_t newCapacity = capacity - step;
	T value = content[newLen];

	if ( newLen < newCapacity ) {
		resize(newCapacity);
		capacity = newCapacity;
	}
		
	len = newLen;
	return value;
}

template<class T>
void ArrayList<T>::resize(size_t size) {
	T* temp = (T*) realloc(content, size*sizeof(T));

	if ( temp == NULL ) {
		throw exception();
	}

	content = temp;
}

template<class T>
T ArrayList<T>::operator[](size_t index) {
	if ( index >= len ) {
		throw exception();
	}
	return content[index];	
}
