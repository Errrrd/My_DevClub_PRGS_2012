#include <stdio.h>

int decrypt(int encrypted, int keyA, int keyB) {
    return (encrypted - keyB) / keyA;
}

int main() {
    int plain1, encrypted1;
    int plain2, encrypted2;
    int len;
    int keyA, keyB;
    int encrypted;
    
    scanf("%d %d %d %d %d", &plain1, &encrypted1, &plain2, &encrypted2, &len);
    
    keyA = (encrypted2 - encrypted1) / (plain2 - plain1);
    keyB = encrypted1 - keyA * plain1;
    
    for ( int i = 1; i < len; i++ ) {
        scanf("%d", &encrypted);
        
        printf("%d ", decrypt(encrypted, keyA, keyB));
    }
    scanf("%d", &encrypted);
    
    printf("%d\n", decrypt(encrypted, keyA, keyB));
    
    return 0;
}
