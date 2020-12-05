int fibonacci(int n) {
    if ( n == 0 ) {
        return 0;
    }
    if ( n*n == 1 ) {
        return 1;
    }
    if ( n <= -2 ) {
        n = -n;
        return (fibonacci(n-2) + fibonacci(n-1))*(-1);
    }
    return (fibonacci(n-2) + fibonacci(n-1));
}
