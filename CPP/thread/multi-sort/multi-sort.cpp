#ifdef _OPENMP

#include <stdio.h>
#include <iostream>
//#include <fstream>
//#include <pthread.h>
#include <omp.h>

#define TH 16 
#define SZ 500003

using namespace std;

template<typename T>
int partition(T array[], int start, int end) {
    int pivot = (start + end) / 2;
    int tmp;
    int hi = end - 1;
    int lo = start;
    
    tmp = array[end];
    array[end] = array[pivot];
    array[pivot] = tmp;
    for ( ; lo <= hi; ) {
        if ( array[end] < array[lo] ) {
            if ( array[end] >= array[hi] ) {
                tmp = array[hi];
                array[hi] = array[lo];
                array[lo] = tmp;
                lo += 1;
                hi -= 1;
            } else {
                hi -= 1;
            }
        } else {
            lo += 1;
        }
    }
    tmp = array[lo];
    array[lo] = array[end];
    array[end] = tmp;
    return lo;
}

template<typename T>
void quickSort(T array[], int lo, int hi) {
    int pivot = partition(array, lo, hi);
    if( lo < pivot - 1 ) {
        quickSort(array, lo, pivot-1);
    }
    if( pivot + 1 < hi ) {
        quickSort(array, pivot+1, hi);
    }
}

template<typename T>
void arrayPrint(FILE *out, T array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

template<typename T>
void merge(T array[], int lo, int mid, int hi) {
    int size = hi - lo;
    T buffer[size];
    for ( int i = 0, j = lo, k = mid; i < size; ) {
        if ( array[j] < array[k] && j < mid ) {
            buffer[i] = array[j];
            i += 1;
            j += 1;
        } else if ( k < hi ) {
            buffer[i] = array[k];
            i += 1;
            k += 1;
        }
        if ( k == hi && j < mid ) {
            buffer[i] = array[j];
            i += 1;
            j += 1;
        }
    }
    for ( int i = 0, j = lo; i < size; i++, j++ ) {
        array[j] = buffer[i];
    }
}

// template<typename T>
// T* find(T object, T array[], int start, int end) {
    // cout << "\nstart find = " << start << " end find = " << end << endl;
    // for( int i = start; i < end; i++ ) {
        // if( array[i] == object ) {
            // return (array+i);
        // }
    // }
    // return NULL;
// }

template<typename T>
int arrayScan(FILE *in, T array[], int len) {
    int size = 0;
    
    for ( ; size < len && fscanf(in, "%d", &array[size]) == 1; size++ );
    return size;
}

int main() {
    //pthread_t thread;
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int *array = new int[SZ];
    int size = arrayScan(in, array, SZ);
    //int object = 1234567;
    int delta = size / TH;
    //int* unknown = NULL;
    
    fclose(in);
    omp_set_dynamic(0);      // запретить библиотеке openmp менять число потоков во время исполнения
    omp_set_num_threads(TH); // установить число потоков в TH
    
    cout << "size = " << size << endl;
    #pragma omp parallel
    {
    #pragma omp for
        for(int i = 0; i < TH; i++ ) {
            int start = delta * i;
            int end = start + delta;
            
            if ( i == TH - 1 ) {
                end = size;
            }
            cout <<"\ncreating thread, " << i << endl;
            
            // if ( unknown == NULL ) {
                // unknown = find(object, array, start, end);
            // }
            
            // if ( unknown != NULL ) {
                // cout << "addres object is " << unknown << ", object = " << *unknown << endl;
            // } 
            // else {
                // cout << "object not found" << endl;
            // }
            quickSort(array, start, end-1);
        }
    }
    for( int step = delta; step < size; ) {
        int start = 0;
        int mid = start + step;
        int end;
        
        step *= 2;
        end = start + step;
        #pragma omp parallel for
        for( ; end < size; start += step, mid += step, end += step ) {
            cout << "\nmerge " << start << '-' << end;
            merge(array, start, mid, end);
        }
        
        if ( mid < size ) {
            {
                cout << "\nmerge " << start << '-' << size;
                merge(array, start, mid, size);
            }
        }
    }
    
    arrayPrint(out, array, size);
    fclose(out);
    
    delete [] array;
    return 0;
}

#endif
