#ifndef MYVECTOR_TEMPLATE_HPP
#define MYVECTOR_TEMPLATE_HPP
#include <cstdlib>
#include <climits>
#include <exception>

template <typename Type> class MyVector {
    private:
        const static float multiplier = 1.2F;
        const static float hysteresis = 0.1F;
        const static size_t initial_memory_alloc_size = 100;

        size_t current_size;
        size_t memory_alloc_size;
        size_t low_memory_alloc_size;
        size_t high_memory_alloc_size;

        Type* content;

        void newsize(size_t new_size) {
            Type* new_content = (Type*) realloc(content, new_size * sizeof(Type));
            if (new_content == NULL) { throw std::exception(); }
            content = new_content;
        }
    public:
        //Member functions (all functions are public member functions)
        /*
            (constructor) Construct vector
            (destructor) Vector destructor
            operator = Copy vector content
        */

        MyVector() : current_size(0), content(NULL) {
            newsize(initial_memory_alloc_size);
            memory_alloc_size = initial_memory_alloc_size;
            low_memory_alloc_size = memory_alloc_size / (multiplier + hysteresis);
            high_memory_alloc_size = memory_alloc_size * multiplier;
        }

        MyVector(size_t malloc_size) : current_size(0), content(NULL) {
            if (malloc_size <= 0) { throw std::exception(); }
            newsize(malloc_size);
            memory_alloc_size = malloc_size;
            low_memory_alloc_size = memory_alloc_size / (multiplier + hysteresis);
            high_memory_alloc_size = memory_alloc_size * multiplier;
        }

        MyVector(size_t malloc_size, const Type& element) : current_size(malloc_size), content(NULL) {
            newsize(initial_memory_alloc_size);
            memory_alloc_size = initial_memory_alloc_size;
            low_memory_alloc_size = memory_alloc_size / (multiplier + hysteresis);
            high_memory_alloc_size = memory_alloc_size * multiplier;

            for ( size_t i = 0; i < current_size; i++ ) {
                content[i] = element;
            }
        }
/*
template <class _InputIterator> vector(_InputIterator __first, _InputIterator __last,
const allocator_type& __a = allocator_type()) : _Base(__a) { typedef typename _Is_integer<_InputIterator>::_Integral _Integral; _M_initialize_aux(__first, __last, _Integral());}*/
/*
        MyVector(const MyVector<Type>::iterator& begin, const MyVector<Type>::iterator& end) : current_size(0), content(NULL) {
            newsize(initial_memory_alloc_size);
            memory_alloc_size = initial_memory_alloc_size;
            low_memory_alloc_size = memory_alloc_size / (multiplier + hysteresis);
            high_memory_alloc_size = memory_alloc_size * multiplier;

            for(iter = begin; iter != end; iter++) {
                //push_back(*iter);
                push_back(*iter);
            }
        }
*/
        MyVector& operator = (const MyVector& other) {
            if(this == &other) return *this;

            delete [] content;

            current_size = other.current_size;
            memory_alloc_size = other.memory_alloc_size;
            low_memory_alloc_size = other.low_memory_alloc_size;
            high_memory_alloc_size = other.high_memory_alloc_size;

            content = new Type [current_size];

            for ( size_t i = 0; i < current_size; i++ ) {
                content[i] = other.content[i];
            }

            return *this;
        }

        MyVector(const MyVector& other) {
            *this = other;
        }

        virtual ~MyVector() {
            delete [] content;
            content = NULL;
        }

        //Iterators
        /*
            begin Return iterator to beginning
            end Return iterator to end
            rbegin Return reverse iterator to reverse beginning
            rend Return reverse iterator to reverse end
        */

        struct iterator {
            private:
                bool reverse_mode;
                Type* pointer;
            public:
                iterator(Type* ptr = NULL, bool rev_mode = false) : pointer(ptr), reverse_mode(rev_mode) {}

                Type& operator * () { return *pointer; }

                Type* operator -> () { return pointer; }

                Type* operator ++ (int) {
                    if ( reverse_mode == false ) {
                        return pointer++;
                    } else {
                        return pointer--;
                    }
                }

                Type* operator ++ () {
                    if ( reverse_mode == false ) {
                        return ++pointer;
                    } else {
                        return --pointer;
                    }
                }

                Type* operator -- (int) {
                    if ( reverse_mode == false ) {
                        return pointer--;
                    } else {
                        return pointer++;
                    }
                }

                Type* operator -- () {
                    if ( reverse_mode == false ) {
                        return --pointer;
                    } else {
                        return ++pointer;
                    }
                }

                bool operator < (const iterator& other) const { return pointer < other.pointer; }

                bool operator > (const iterator& other) const { return pointer > other.pointer; }

                bool operator == (const iterator& other) const { return pointer == other.pointer; }

                bool operator != (const iterator& other) const { return !(operator == (other)); }
        };

        iterator begin() const {
            return iterator(content, false);
        }

        iterator rbegin() const {
            return iterator(&content[current_size - 1], true);
        }

        iterator end() {
            return iterator(&content[current_size], false);
        }

        iterator rend() {
            return iterator(&content[-1], true);
        }

        //Capacity
        /*
            size Return size
            max_size Return maximum size
            resize Change size
            capacity Return size of allocated storage capacity
            empty Test whether vector is empty
            reserve Request a change in capacity
        */

        size_t size() const { return current_size; }

        size_t max_size() const { return ULONG_MAX / sizeof(Type); }

        void resize(size_t new_size, const Type& element = 0) {
            if ( new_size < current_size ) {
                while ( new_size < current_size ) {
                    pop_back();
                }
            } else {
                if ( new_size > memory_alloc_size ) { reserve(new_size); }
                while ( new_size > current_size ) {
                    push_back(element);
                }
            }
        }

        size_t capacity() const { return memory_alloc_size; }

        bool empty() const {
            if (current_size == 0) return true;
            return false;
        }

        void reserve(size_t new_capacity) {
            if ( new_capacity > memory_alloc_size ) {
                memory_alloc_size = new_capacity;
                high_memory_alloc_size = memory_alloc_size * (multiplier + hysteresis);
                low_memory_alloc_size = memory_alloc_size / multiplier;
                newsize(memory_alloc_size);
            }
        }

        //Element access
        /*
            operator[] Access element
            at Access element
            front Access first element
            back Access last element
        */

        Type operator [] (const size_t index) const {
            if ( index >= current_size ) {
                throw std::exception();
            }
            return content[index];
        }

        Type at(const size_t index) const {
            return operator [] (index);
        }

        Type front() const { return content[0]; }

        Type back() const { return content[current_size - 1]; }

        //Modifiers
        /*
            assign Assign vector content
            push_back Add element at the end
            pop_back Delete last element
            insert Insert elements
            erase Erase elements
            swap Swap content
            clear Clear content
        */

        void push_back(const Type& element) {
            if (current_size + 1 == memory_alloc_size) {
                newsize(high_memory_alloc_size);
                memory_alloc_size = high_memory_alloc_size;
                high_memory_alloc_size = memory_alloc_size * (multiplier + hysteresis);
                low_memory_alloc_size = memory_alloc_size / multiplier;
            }
            //Type* content[current_size] = new Type;
            content[current_size] = element;
            current_size++;
        }

        void pop_back() {
            //delete content[current_size - 1];
            current_size--;
            if (current_size < low_memory_alloc_size) {
                newsize(low_memory_alloc_size);
                memory_alloc_size = low_memory_alloc_size;
                low_memory_alloc_size = memory_alloc_size / (multiplier + hysteresis);
                high_memory_alloc_size = memory_alloc_size * multiplier;
            }
        }
};

#endif
