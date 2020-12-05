#include <stdio.h>

#define SIZE 5

void matrixMultiply(int matrix[SIZE][SIZE], int size, int multiplier) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            matrix[i][j] *= multiplier;
        }
    }
}

void matrixScan(FILE *in, int matrix[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < size; col++ ) {
            fscanf(in, "%d", &matrix[col][row]);
        }
    }
}

void matrixPrint(FILE *out, int matrix[SIZE][SIZE], int size) {
    int last = size - 1;
    
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < last; col++ ) {
            fprintf(out, "%d ", matrix[col][row]);
        }
        fprintf(out, "%d\n", matrix[last][row]);
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int matrix[SIZE][SIZE];
    int multiplier = 3;
    
    void matrixScan(in, matrix, SIZE);
    fclose(in);
    void matrixPrint(out, matrix, SIZE);
    void matrixMultiply(matrix, SIZE, multiplier);
    void matrixPrint(out, matrix, SIZE);
    fclose(out);
    return 0;
}