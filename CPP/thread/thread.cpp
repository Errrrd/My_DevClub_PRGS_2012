#ifdef _OPENMP

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <omp.h>

//#include <thread>

#define TH 4 
#define SZ 6000000

using namespace std;

template<typename T>
T* find(T object, T array[], int start, int end) {
    //cout << "start find = " << start << " end find = " << end << endl;
    for( int i = start; i < end || array[i] != object; i++ ) {
        if( array[i] == object ) {
            return (array+i);
        }
    }
    return NULL;
}

template<typename T>
int arrayScan(FILE *in, T array[], int len) {
    int size = 0;
    for ( ; size < len && fscanf(in, "%d", &array[size]) == 1; size++ );
    return size;
}

int main() {
    //pthread_t thread;
    FILE *in = fopen("task.in", "r");
    //FILE *out = fopen("task.out", "w");
    int *array = new int[SZ];
    int size = arrayScan(in, array, SZ);
    int object = 1234567;
    int delta = size / TH;
    int* unknown = NULL;
    
    fclose(in);

    omp_set_dynamic(0);      // запретить библиотеке openmp менять число потоков во время исполнения
    omp_set_num_threads(TH); // установить число потоков в TH
    
    cout << "size = " << size << endl;
    for(int i = 0; i < TH; i++ ){
        int start = delta * i;
        int end = start + delta;
        
        //cout << "\nstart " << start << " end " << end << endl;
        if ( end > size ) {
            end = size;
        }
        unknown = find(object, array, start, end);
        
        if ( unknown != NULL ) {
            cout << "\naddres object is " << unknown << ", object = " << *unknown << endl;
        } else {
            cout << "\nobject not found" << endl;
        }
    }
    delete [] array;
    return 0;
}

#endif
