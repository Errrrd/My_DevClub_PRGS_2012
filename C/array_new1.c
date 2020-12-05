#define SIZE 10

int factorial(int n) {
    if ( n < 0 ) {
        return -1;
    }
    if ( n == 0 ) {
        return 1;
    }
    return factorial(n-1) * n;
}

void arraiRead(FILE *in, int array[]) {
    for int i = 0; i < SIZE; i++ ) {
        fscanfs(in, "%d", &array[i]);
    }
}

void arraiModify(FILE *in, int array[]) {
    for int i = 0; i < SIZE; i++ ) {
       array[i] = factorial(array[i];
    }
}

void arraiPrint(FILE *out, int array[]) {
    int last = SIZE - 1;
    
    for int i = 0; i < last; i++ ) {
        fprintf(out, "%d", &array[i]);
    }
    fprintf(out, "%d", &array[last]);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int array[SIZE];
    
    arraiRead(in, array);
    arraiPrint(out, array);
    
    return 0;
}