#ifdef _OPENMP

#include <stdio.h>
#include <iostream>
//#include <fstream>
//#include <pthread.h>
#include <omp.h>

#define TH 7 
#define SZ 5000003

using namespace std;

template<typename T>
T* find(T object, T array[], int start, int end) {
    //cout << "\nstart find = " << start << " end find = " << end << endl;
    for( int i = start; i < end; i++ ) {
        if( array[i] == object ) {
            return (array+i);
        }
    }
    return 0;
}

template<typename T>
int arrayScan(FILE *in, T array[], int len) {
    int size = 0;
    
    for ( ; size < len && fscanf(in, "%d", &array[size]) == 1; size++ );
    return size;
}

int main() {
    FILE *in = fopen("task.in", "r");
    //FILE *out = fopen("task.out", "w");
    int *array = new int[SZ];
    int size = arrayScan(in, array, SZ);
    int object = 1234567;
    int delta = size / TH;
    int* unknown = NULL;
    int* result = NULL;
    
    fclose(in);
    omp_set_dynamic(0);      // запретить библиотеке openmp менять число потоков во время исполнения
    omp_set_num_threads(TH); // установить число потоков в TH
    
    cout << "size = " << size << endl;
    #pragma omp parallel for
    for(int i = 0; i < TH; i++ ) {
        int start = delta * i;
        int end = start + delta;
        
        if ( i == TH - 1 ) {
            end = size;
        }
        
        cout <<"\ncreating thread, " << i << endl;
        if ( result == NULL ) {
            unknown = find(object, array, start, end);
            // unknown = find(object, array, 0, size);
        }
        if ( unknown != NULL ) {
            result = unknown;
        }
    }
    if ( unknown != NULL ) {
        cout << "addres object is " << result << ", object = " << *result << endl;
    } else {
        cout << "object not found " << endl;
    }
    //arrayPrint(out, array, size);
    //fclose(out);
    
    delete [] array;
    return 0;
}

#endif
