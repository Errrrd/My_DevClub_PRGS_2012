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
        const static int step = 100;
		const static float multiplier = 1.2;
		size_t capacity;
		size_t len;
        T* content;
        T* pre;
        T* suc;
        
		void resize(size_t);

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
                
                // iterator<T>& begin();
                
                // iterator<T>& end();
                
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
                
                // reverse_iterator<T>& rbegin();
                
                // reverse_iterator<T>& rend();
                
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
                this->content = other.content;
                this->pre = other.pre;
                this->suc = other.suc;
        }
        
        bool operator== (const LinkedList& other) {
                return (this->capacity == other.capacity && this->len = other.len && this->content == other.content && this->pre == other.pre && this->suc = other.suc);
        }
        
        T* begin() const {
            return content;
        }

        T* end() {
            return content + len;
        }
        
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
        
        
        // front();
        
        // back();
        
        // T pop_back();
        
        // T pop_front();
        
        void push_back(T&);
        
        // T push_front();
        
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
	T* temp = (T*) realloc(content, newSize*sizeof(T));

	if ( temp == NULL ) {
		throw exception();
	}
	content = temp;
}

template<class T>
LinkedList<T>::LinkedList() : len(0), capacity(step), content(NULL) {
	resize(step);
    pre = content;
    suc = content;
}

template<class T>
LinkedList<T>::LinkedList(size_t len) : len(len), capacity(len), content(NULL) {
	if ( len >= step ) {
        resize(len);
    } else {
        resize(step);
    }
    pre = content - 1;
    suc = content + len;
}

template<class T>
LinkedList<T>::LinkedList(const T& content) : len(1), capacity(step), content(content) {
	resize(step);
    pre = content - 1;
    suc = content + 1;
}

template<class T>
LinkedList<T>::LinkedList(size_t len, const T& content) : len(len), capacity(len), content(content) {
	resize(len);
    pre = content - 1;
    suc = content + len;
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
// void LinkedList<T>::pop_back() {

// }
        
// template<class T>        
// void LinkedList<T>::pop_front() {

// }
        
// template<class T>        
// voidLinkedList<T>::push_back() {
    
// }

template<class T>
void LinkedList<T>::push_back(T& value) {
    T* element = &(value);
    T* last =  content+len;

    if ( len + 1 == capacity ) {
		size_t newCapacity = capacity * multiplier;

		resize(newCapacity);
		capacity = newCapacity;	
	}
    if ( len == 0 ) {
        content = element;
        len = 1;
        pre = content - 1;
        suc = content + 1;
    } 
    last = element;
    len += 1;
    suc = (content + len);
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
