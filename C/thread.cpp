#include <cstdlib>
#include <iostream>
 
#include <thread>

#define TH 2 

using namespace std;

template<typename T>
T* find(T object, T* array, int len) {
    for( int i = 0; i < len; i++ ) {
        if( *(array + i) == object ) {
            return (array+i);
        }
        return NULL;
    }
}

int main() {
    
    
    return 0;
}