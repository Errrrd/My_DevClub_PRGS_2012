#include <stdio.h>

#define LIMIT 32
int main() {
    int len;
    
    scanf("%d", &len);
    
    for ( int i = 0; i < LIMIT; i++ ) {
    ����� - 1
    ���������� - 2
        0
        1
    ����� - 2
    ���������� - 3
        00
        01
        10
    ����� - 3
    ���������� - 5
        000
        001
        010
        100
        101
    ����� - 4
    ���������� - 8
        0000
        0001
        0010
        0100
        1000
        0101
        1001
        1010
    ����� - 5
    ���������� - 13
        00000
        00001
        00010
        00100
        01000
        10000
        00101
        01001
        01010
        10001
        10010
        10100
        10101
    ����� - 6
    ���������� - 
        000000
        000001
        000010
        000100
        001000
        010000
        100000
        000101
        001001
        001010
        010001
        010010
        010100
        100001
        100010
        100100
        101000
        010101
        100101
        101001
        101010
    
    
    }
    
    return 0;
}