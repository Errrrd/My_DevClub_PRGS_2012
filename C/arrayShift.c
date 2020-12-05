void arrayShift(int array[], int size, int shift) {
    int tmp;
    int tmpshift = shift % size;
    int last = size - 1;
    
    if ( tmpshift < size / 2 ) {
        for (int i = 0, j = size - tmpshift; tmpshift < last; i++, j++) {
            tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        }
    } else {
        for ( tmp = array[last]; last > 0; last-- ) {
            array[last] = array[last-1];
        }
        array[0] = tmp;
    }
    
    
    
}
0-5
1-6
2-7
3-8
4-9
5-10

Написать функцию:
void arrayShift(int array[], int size, int shift)
Реализовать циклический сдвиг массива на shift элементов вправо. Максимизировать производительность при оптимальном использовании памяти.