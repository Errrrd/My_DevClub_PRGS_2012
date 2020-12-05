int arraySum(int array[], int size) {
    int limit= size-1
    if ( limit >=0 ) {
        return array[limit] + arraySum(array, limit);
    }
    return 0;
}
