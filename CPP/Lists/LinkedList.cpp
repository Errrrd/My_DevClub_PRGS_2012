 // Посмотреть по документации интерфейс для stl::vector и stl::list.
// Написать классы LinkedList (список) и LinkedList (связанный список), соответствующие этим интерфейсам.

// Бонус: встроить методы для обработки этих структур, соответствующие алгоритмам, рассмотренным на более ранних уикендах BootCamp.

// Это задание необходимо выполнить, если в дальнейшем вы планируете работать с С++.

 
        // const static int step = 100;
		// const static float multiplier = 1.2;
		// size_t capacity;
		// size_t len;
        // T* content;
        // Link link;
        
		// void resize(size_t);

#include <cstdlib>
#include <cstddef>
#include <exception>

#include "linkedList.h"

using namespace std;
    
void LinkedList<T>::resize(size_t newSize) {
	T* temp = (T*) realloc(content, newSize*sizeof(T));

	if ( temp == NULL ) {
		throw exception();
	}
	content = temp;
}

LinkedList<T>::LinkedList() : len(0), capacity(step), content(NULL) {
	resize(step);
    link.next = NULL;
    link.prev = NULL;
}

LinkedList<T>::LinkedList(T& content) : len(1), capacity(step), content(content) {
	resize(step);
    link.next = NULL;
    link.prev = NULL;
}

LinkedList<T>::~LinkedList() {
	free(content);
}

LinkedList<T>::assign
LinkedList<T>::back
LinkedList<T>::begin
LinkedList<T>::clear
LinkedList<T>::empty
LinkedList<T>::end
LinkedList<T>::erase
LinkedList<T>::front
LinkedList<T>::insert
LinkedList<T>::max_size
LinkedList<T>::merge
LinkedList<T>::operator=
LinkedList<T>::pop_back
LinkedList<T>::pop_front
LinkedList<T>::push_back
LinkedList<T>::push_front
LinkedList<T>::rbegin
LinkedList<T>::remove
LinkedList<T>::rend
LinkedList<T>::resize
LinkedList<T>::reverse
LinkedList<T>::size
LinkedList<T>::swap
LinkedList<T>::unique

void LinkedList<T>::append(T value) {
	if ( len + 1 == capacity ) {
		size_t newCapacity = capacity * multiplier;

		resize(newCapacity);
		capacity = newCapacity;	
	}

	content[len] = value;
	len += 1;
}

T LinkedList<T>::pop() {
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
