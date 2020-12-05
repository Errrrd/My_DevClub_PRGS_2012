#include <stdio.h>

typedef enum {
    spade,
    clab,
    diamond,
    heart
} Suit;

typedef enum {
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    quin,
    king,
    ace,
    joker
} Grade;

typedef struct {
    Grade grade;
    Suit suit;
} Card;

int main() {
    Card spadeQuin;
    
    spadeQuin.grade = quin;
    spadeQuin.suit = spade;
    
    if( spadeQuin.suit == spade && spadeQuin.grade == quin ) {
        printf("thys is Spade Quin\n");
    }
    
    return 0;
}
