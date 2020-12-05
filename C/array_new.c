#define SIZE 10

int main() {
    int array[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    for ( int j = 1, i = 0; i < SIZE; i++, j++ ) {
        array[i] = j;
    }
    
    for ( int i = 0; i < SIZE; i++ ) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}