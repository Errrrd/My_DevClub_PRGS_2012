#include <stdio.h>

#define LEN1 17
#define LEN2 19

int arrayScan(FILE *in, int array[], int limit) {
    int size = 0;
    
    for ( ; size < limit && fscanf(in, "%d", &array[size]) == 1; size++ );
    return size;
}

void arrayPrint(FILE *out, int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

void arrayMerge(int target[], int src1[], int len1, int src2[], int len2) {
    int i, j, k;
    
    for ( i = 0, j = 0, k = 0; i < len1 && j < len2; ) {
        if ( src1[i] <= src2[j] ) {
            target[k] = src1[i];
            i += 1;
        } else {
            target[k] = src2[j];
            j += 1;
        }
        k = i + j;
    }
    for ( ; j < len2; j++, k++ ) {
        target[k] = src2[j];
    }
    for ( ; i < len1; i++, k++ ) {
        target[k] = src1[i];
    }
}

int main() {
    FILE *in1 = fopen("task1.in", "r");
    FILE *in2 = fopen("task2.in", "r");
    FILE *out = fopen("task.out", "w");
    int src1[LEN1];
    int src2[LEN2];
    int target[LEN1+LEN2];
    
    arrayScan(in1, src1, LEN1);
    fclose(in1);
    arrayScan(in2, src2, LEN2);
    fclose(in2);
    arrayPrint(out, src1, LEN1);
    arrayPrint(out, src2, LEN2);
    arrayMerge(target, src1, LEN1, src2, LEN2);
    arrayPrint(out, target, LEN1+LEN2);
    fclose(out);
    
    return 0;
}
