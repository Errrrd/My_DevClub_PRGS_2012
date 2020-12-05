// binarySequence
// В файле task.in дана последовательность символов – нулей и единиц.
// Вывести в task.out минимально необходимое число обменов пар значений для упорядочивания последовательности по неубыванию.

#include <stdio.h>

int intScan(FILE *in) {
    int number;
    
    fscanf(in, "%d", &number);
    return number;
}

int arrayScan(FILE *in, int array[], int limit) {
    int size = 0;
    
    for ( ; size < limit && fscanf(in, "%c", &array[size]) == 1; size++ );
    return size;
}

void arrayPrint(FILE *out, int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
        printf("%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
    printf("%d\n", array[last]);
}

int main() {
    FILE *in = fopen("taskbin.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = intScan(in);
    int array[len];
     
    printf("%d\n", len);
    printf("%d\n", arrayScan(in, array, len));
    //arrayPrint(out, array, len);
    fclose(in);
    //arrayPrint(out, array, len);
    fclose(out);
    
    return 0;
}


