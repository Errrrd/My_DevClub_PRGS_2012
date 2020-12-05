// Посмотреть по документации интерфейс для stl::vector и stl::list.
// Написать классы LinkedList (список) и LinkedList (связанный список), соответствующие этим интерфейсам.

// Бонус: встроить методы для обработки этих структур, соответствующие алгоритмам, рассмотренным на более ранних уикендах BootCamp.

// Это задание необходимо выполнить, если в дальнейшем вы планируете работать с С++.

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include <exception>

using namespace std;

template <class T> 
class LinkedList {
	private:
        struct Element{
            T* element;
            T* pre;
            T* suc;
        };
        const static int step = 100;
		const static float multiplier = 1.2;
		size_t capacity;
		size_t len;
        Element* content;
            
        
		void resize(size_t);
    protected:
        Element* first;
        Element* last;
        Element* rfirst;
        Element* rlast;

	public:
        // template<class T>
        // class iterator {
            // private:
                // T* element;
                // T* next;
                // T* prev;
                
            // public:
                // iterator();
                
                // ~iterator();
                
                // iterator<T>& first();
                
                // iterator<T>& last();
                
                // iterator<T>& operator=(const T&);
                                
                // void operator++(const T&);
                
                // void operator!=(const T&);
                
                // void operator==(const T&);
        // };
        
        // template<class T>
        // class reverse_iterator {
            // private:
                // T* element;
                // T* next;
                // T* prev;
            
            // public:
                // reverse_iterator();
                
                // ~reverse_iterator();
                
                // reverse_iterator<T>& rfirst();
                
                // reverse_iterator<T>& rlast();
                
                // reverse_iterator<T>& operator=(const T&);
                                
                // reverse_iterator<T>& operator++();
                
                // reverse_iterator<T>& operator!=(const T&);
                
                // reverse_iterator<T>& operator==(const T&);
        // };
    
		LinkedList();
        
        LinkedList(size_t);
                
        LinkedList(const T&);
        
        LinkedList(size_t, const T&);

		~LinkedList();
        
        LinkedList& operator= (const LinkedList& other) {
            if(this == &other) {
                return *this;
            }

            this->capacity = other.capacity;
            this->len = other.len;
            
            free(this->content);
            resize(this->len);
            
            this->content = other->content;
            this->first = other->first;
            this->last = other->last;
            this->rfirst = other->rfirst;
            this->rlast = other->rlast;
        }
        
        bool operator== (const LinkedList& other) {
                return (this->capacity == other.capacity && this->len = other.len && this->content == other->content && this->first == other->first && this->last = other->last && this->rfirst == other->rfirst && this->rlast = other->rlast);
        }
        
        Element* begin() const {
            return first;
        }

        Element* end() {
            return last;
        }
        
        Element* rbegin() const {
            return rfirst;
        }

        Element* rend() {
            return rlast;
        }
        
        // struct iterator {
            // private:
                // T* pointer;
                
            // public:                
                // iterator(T* p = NULL) {
                    // pointer = p;
                // }
                
                // T& operator* () {
                    // return *pointer; 
                // }
                
                // T* operator++ () {
                        // return pointer++;
                // }
                
                // T* operator++ (int) {
                        // return pointer++;
                // }

                // bool operator < (const iterator& other) const { return pointer < other.pointer; }

                // bool operator > (const iterator& other) const { return pointer > other.pointer; }

                // bool operator == (const iterator& other) const { return pointer == other.pointer; }

                // bool operator != (const iterator& other) const { return !(operator == (other)); }
        // };
        
        
        // front();
        
        // back();
        
        // T pop_back();
        
        // T pop_front();
        
        void push_back(T&);
        
        void push_front(T&);
        
        // empty();
        
        // clear();
        
        // erase();
        
        // insert();
        
        // max_size();

        // remove()
       
        // resize();
        
        // size();
};

template<class T>
void LinkedList<T>::resize(size_t newSize) {
	Element* temp = (Element*) realloc(content, newSize*sizeof(Element));

	if ( temp == NULL ) {
		throw exception();
	}
	content = temp;
}

template<class T>
LinkedList<T>::LinkedList() : len(0), capacity(step) {
	resize(step);
    content = NULL;
    first = content;
    last = content;
    rfirst = content;
    rlast = content;
}

template<class T>
LinkedList<T>::LinkedList(size_t len) : len(len) {
	if ( len >= step ) {
        resize(len);
        capacity = len;
    } else {
        resize(step);
        capacity = step;
    }
    content.pre = NULL;
    content.element = NULL;
    content.suc = NULL;
    first = content;
    last = content;
    rfirst = content;
    rlast = content;
}

template<class T>
LinkedList<T>::LinkedList(const T& element) : len(1), capacity(step) {
	resize(step);
    
    content.element = element;
    content.pre = NULL;
    content.suc = NULL;
    first = content;
    rlast = content;
    last.element = NULL;
    last.pre = content.element;
    last.suc = NULL;
    rfirst.element = NULL;
    rfirst.pre = NULL;
    rfirst.suc = content.element;
}

template<class T>
LinkedList<T>::LinkedList(size_t len, const T& element) : len(len), capacity(len) {
	resize(len);
    content.element = element;
    content.pre = NULL;
    content.suc = NULL;
    first = content;
    rlast = content;
    last.element = NULL;
    last.pre = content.element;
    last.suc = NULL;
    rfirst.element = NULL;
    rfirst.pre = NULL;
    rfirst.suc = content.element;
}

template<class T>
LinkedList<T>::~LinkedList() {
	free(content);
}

// template<class T>
// T LinkedList<T>::front() {

// }
        
// template<class T>
// T LinkedList<T>::back() {

// }

// template<class T>        
// Element LinkedList<T>::pop_back() {

// }
        
// template<class T>        
// Element LinkedList<T>::pop_front() {

// }
        
// template<class T>        
// void LinkedList<T>::push_back() {
    
// }

template<class T>
void LinkedList<T>::push_back(T& value) {
    T* element = &(value);

    if ( len + 1 == capacity ) {
		size_t newCapacity = capacity * multiplier;

		resize(newCapacity);
		capacity = newCapacity;	
	}
    if ( len == 0 ) {
        content.element = element;
        len = 1;
    } else {
        content.pre = content.element;
        content.element = element;
        content.suc = NULL;
        len += 1;
    }
}

template<class T>
void LinkedList<T>::push_front(T& value) {
    T* element = &(value);

    if ( len + 1 == capacity ) {
		size_t newCapacity = capacity * multiplier;

		resize(newCapacity);
		capacity = newCapacity;	
	}
    if ( len == 0 ) {
        content.elemnt = element;
        last.pre = content.element;
        rfirst.suc = content.element;
        len = 1;
    } else {
        content.suc = content.element;
        content.element = element;
        content.pre = NULL;
        last.pre = content.element;
        rfirst.suc = content.element;
        len += 1;
    }
}
        
// template<class T>        
// bool LinkedList<T>::empty() {

// }
        
// template<class T>        
// void LinkedList<T>::clear() {

// }
        
// template<class T>        
// void LinkedList<T>::erase() {

// }
        
// template<class T>        
// void LinkedList<T>::remove() {

// }
        
// template<class T>        
// size_t LinkedList<T>::size() {

// }

// template<class T>        
// size_t LinkedList<T>::max_size() {

// }

#endif
