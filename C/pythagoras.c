#include <stdio.h>

void pythPrint(int x) {
    for(int i = x / 10; i != 0; i /= 10){
        printf(" ");
    }
}
void print_(int x) {
    for(int i = x / 10; i != 0; i /= 10){
        printf("_");
    }
}

int main() {
    int startacr, endacr;
    int startver, endver;
    int i, j;
    
    scanf("%d %d %d %d", &startacr, &endacr, &startver, &endver);
    
    printf(" ");
    pythPrint(endver);
    printf(" | ");
    for ( j = startacr; j < endacr; j++ ) {
        pythPrint(endver*j);
        printf("%d ", j);
    }
    pythPrint(endver*j);
    printf("%d \n", j);
    
    printf("_");
    print_(endver);
    printf("_|_");
    for ( j = startacr; j < endacr; j++ ) {
        print_(endver*j);
        print_(j);
        printf("__");
    }
    print_(endver*j);
    print_(j);
    printf("_\n");
    
    for ( i = startver; i <= endver; i++ ) {
        printf(" ");
        pythPrint(endver);
        printf(" | ");
        for ( j = startacr; j < endacr; j++ ) {}
    }
    
    
}