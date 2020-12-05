#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <cstdlib>
#include <iostream>
#include <exception>

using namespace std;

template<class T>
class ArrayList {
	private:
		size_t capacity;
		size_t len;
		T* content;
		const static int step = 100;
		const static float multiplier = 1.2;

		void resize(size_t);

	public:
		ArrayList();

		~ArrayList();
        
        struct iterator {
            private:
                T* pointer;
                
            public:                
                iterator(T* p = NULL) {
                    pointer = p;
                }
                
                T& operator* () {
                    return *pointer; 
                }
                
                T* operator++ () {
                        return pointer++;
                }
                
                T* operator++ (int) {
                        return pointer++;
                }

                bool operator < (const iterator& other) const { return pointer < other.pointer; }

                bool operator > (const iterator& other) const { return pointer > other.pointer; }

                bool operator == (const iterator& other) const { return pointer == other.pointer; }

                bool operator != (const iterator& other) const { return !(operator == (other)); }
        };
        
        T* begin() const {
            return content;
        }

        T* end() {
            return &content[len];
        }

		void push_back(T);

		T pop_back();

		T operator[](size_t);
};

template<class T>
ArrayList<T>::ArrayList() : len(0), capacity(step), content(NULL) {
	resize(step);
}

template<class T>
ArrayList<T>::~ArrayList() {
	free(content);
}

template<class T>
void ArrayList<T>::push_back(T value) {
	if ( len + 1 == capacity ) {
		size_t newCapacity = capacity * multiplier;

		resize(newCapacity);
		capacity = newCapacity;	
	}

	content[len] = value;
	len += 1;
    cout << 'a';
}

template<class T>
T ArrayList<T>::pop_back() {
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

#endif
