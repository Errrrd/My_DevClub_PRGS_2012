#include <stdio.h>

#define SIZE 1001

void priceScan(unsigned long long array[], int limit) {
    for ( int i = 0; i < limit; i++ ) {
        array[i] = 0;
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    unsigned long long amounPrice[SIZE];
    unsigned int amount, price;
    unsigned int farmerQuantity, amountNeeded;
    unsigned long long minPrice = 0;
    unsigned long long amountTmp;
    
    priceScan(amounPrice, SIZE);
    fscanf(in, "%u %u", &farmerQuantity, &amountNeeded);
    
    for ( int i = 0; i < farmerQuantity; i++ ) {
        fscanf(in, "%u %u", &amount, &price);
        if ( amounPrice[price] < 300000000 ) {
            amounPrice[price] += amount;
        }
    }
    fclose(in);
    
    amountTmp = amountNeeded;
    for ( unsigned long long i = 1; i < SIZE && amountTmp > 0; i++ ) {
        if ( amountTmp >= amounPrice[i] ) {
            minPrice += amounPrice[i] * i;
            amountTmp -= amounPrice[i];
        } else {
            minPrice += amountTmp * i;
            amountTmp = 0;
        }
    }
    if ( amountTmp ) {
        minPrice = 0;
    }
    fprintf(out, "%llu\n", minPrice);
    fclose(out);
    
    return 0;
}
